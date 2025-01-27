#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

#include <mpi.h>

#include "Cluster.h"
#include "Point.h"

using namespace std;

int MAX_ITERATION = 10;

const int LENTAG = 0, STAT = 1, DATAPOINTTAG = 2, DATACLUSTERTAG = 3, DATASUMCLUSTERTAG = 4;

// string path_gcloud = "/home/galan/ACAproject/MPI-K-Means-Clustering-main/";
string path_gcloud = "/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/";

string dataset = path_gcloud + "DataSet/DataSet10000x10.txt";

void writeExTime(int cs, int tnp, int pd, int K, double time){
    ofstream f;
    f.open((path_gcloud + "Parallel/results_ex_proc.txt").c_str(), ios::app);
    f << cs << ";" << tnp << ";" << pd << ";" << K << ";" << time << endl;
    f.close();
}

void readDataset(vector<Point*>& points, const string& filePath) {
    ifstream dataset(filePath);

    if (!dataset.is_open()){
        cout << "[ERR] CAN'T OPEN DATASET FILE" << endl;
        return;
    }

    string line;
    while (getline(dataset, line)) {
        vector<string> elems;
        stringstream ss(line);
        string elem;

        while (getline(ss, elem, ',')) {
            elems.push_back(elem);
        }

        Point *point = new Point(elems.size());
        for (int i = 0; i < elems.size(); i++) {
            point->set_value(i, stod(elems[i]));
        }

        points.push_back(point);
    }

    dataset.close();
}

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Status status;

    int my_rank, commSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);

    if(my_rank == 0){
        int finish = 0;

        double start_time, end_time;

        start_time = MPI_Wtime();

        // Reading the dataset...
        vector<Point*> points_temp_;
		if(argc == 2){
			// Se ho passato un argomento
			dataset = path_gcloud + "DataSet/" + argv[1];
		}
        readDataset(points_temp_, dataset);

        int point_dim = points_temp_[0]->get_dim();
        int points_number = points_temp_.size();

        int K = sqrt(points_number/2);

        Cluster::create_clusters(K, point_dim);

        int points_per_proc_ = points_number / commSize;
        int bufferSize = 2 +  point_dim * points_per_proc_;

        double *buffer, *buffer2;
        buffer = new double[bufferSize];

        // Sends <points_per_proc_> to all processors
        MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

        /*
         * Starts from 1 because the master works on the last batch of points
         * so the first processor will work on the first batch of points, ecc..
        */

        for(int i = 1; i < commSize; i++){
            int startIndex = (i - 1) * points_per_proc_;
            int endIndex = startIndex + points_per_proc_;
            Point::serializePoint(buffer, startIndex, endIndex, point_dim);

            MPI_Send(buffer, bufferSize, MPI_DOUBLE, i, DATAPOINTTAG, MPI_COMM_WORLD);
        }

        delete[] buffer; buffer = nullptr;

        bufferSize = 2 + K * point_dim;
        buffer = new double[bufferSize];

        MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

        // Sends number of clusters and init centroids
        Cluster::serializeCluster(buffer);
        MPI_Bcast(buffer, bufferSize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        // Start of the task
        double precTMSE, tmse = 0;

        while(true) {
            Cluster::reset_clusters();

            // Master works on the last batch of points <processors_point>
            int startIndex = (commSize - 1) * points_per_proc_;
            int endIndex = points_number;
            Cluster::map_point_to_cluster(startIndex, endIndex);

            // Gets the sum of the points of each cluster (of the master's points)
            Cluster::sum_points_clusters();

            /* // ..redundant..
            * int cluster_number_ = K;
            * int centroid_dim_ = point_dim;
            */

            bufferSize = K + K * point_dim;

            buffer2 = new double[bufferSize];
            buffer = new double[bufferSize];

            Cluster::serializeSumCoordsCluster(buffer2);

            // 1--- REDUCE
            MPI_Reduce(buffer2, buffer, bufferSize, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            Cluster::deserializeSumCoordsCluster(buffer);

            // Gets new centroids
            Cluster::find_centroid_clusters();

            precTMSE = tmse;

            delete[] buffer; buffer = nullptr;

            buffer = new double[1];
            buffer2 = new double[1];

            // Gets the static value sum_points_distance_ of all cluster (of the master's points)
            buffer2[0] = Cluster::getSumPointsDistance();

            // 2--- REDUCE
            MPI_Reduce(buffer2, buffer, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            // Sets the sum_points_distance_ (in the master) derived by the sums of each slave's sum_points_distance_
            Cluster::setSumPointsDistance(buffer[0]);

            tmse = Cluster::tMSE();

            // [DEBUG] -- CLion
            /*int debug = 0;
            while(debug == 0) {
                sleep(1);
            }*/

            printf("MAX_ITERATION: %d, tmse: %f, precTMSE: %f\n", MAX_ITERATION, tmse, precTMSE);
            if(!(--MAX_ITERATION && ((tmse < precTMSE) || precTMSE == 0))){ break;}

            MPI_Bcast(&finish, 1, MPI_INT, 0, MPI_COMM_WORLD);

            // If not finished, calculates new centroids and sends them to the slaves
            bufferSize = K * point_dim;
            buffer = new double[bufferSize];

            Cluster::serializeCentroids(buffer);
            
            MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);
            MPI_Bcast(buffer, bufferSize, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        }

        // End condition
        finish = 1;
        MPI_Bcast(&finish, 1, MPI_INT, 0, MPI_COMM_WORLD);

        end_time = MPI_Wtime();

        // printf("That took %f seconds\n", end_time - start_time);
        printf("%f\n", end_time - start_time);

        /* [DEBUG]
         * [MASTER] to save the execution time of the program
         * <processi-- commSize> <numero di punti-- points_number> <dimensione punti-- point_dim> <numero di cluster> <tempo di esecuzione>
        */
        // writeExTime(commSize, points_number, point_dim, K, end_time - start_time);

        // Cluster::saveCentroids(my_rank, 205);
        // Cluster::saveClusters(my_rank, 206);
    }

    if(my_rank != 0){
        int finish;

        int bufferSize;
        double *buffer, *buffer2;

        // Gets <points_per_proc_>
        MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

        buffer = new double[bufferSize];
        MPI_Recv(buffer, bufferSize, MPI_DOUBLE, 0, DATAPOINTTAG, MPI_COMM_WORLD, &status);

        Point::deserializePoint(buffer);

        // Gets number of clusters and centroids
        MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

        delete[] buffer; buffer = nullptr;

        buffer = new double[bufferSize];

        MPI_Bcast(buffer, bufferSize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        Cluster::deserializeCluster(buffer);

        delete[] buffer; buffer = nullptr;

        while(true) {
            Cluster::reset_clusters();

            Cluster::map_point_to_cluster();

            // Calculates the vectorial sums of the points that the slave is working with
            Cluster::sum_points_clusters();

            int cluster_number_ = Cluster::get_sclusters_();
            int centroid_dim_ = Cluster::get_cluster(0)->get_centroid()->get_dim();

            bufferSize = cluster_number_ + cluster_number_ * centroid_dim_;

            buffer = new double[bufferSize];
            buffer2 = new double[bufferSize];
            Cluster::serializeSumCoordsCluster(buffer);

            // 1--- REDUCE
            MPI_Reduce(buffer, buffer2, bufferSize, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            delete[] buffer; buffer = nullptr;
            delete[] buffer2; buffer2 = nullptr;

            buffer = new double[1];
            buffer2 = new double[1];

            // Get the sum_points_distance_ of the clusters
            buffer[0] = Cluster::getSumPointsDistance();

            // 2--- REDUCE | Sends the master its sum_points_distance_
            MPI_Reduce(buffer, buffer2, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

            MPI_Bcast(&finish, 1, MPI_INT, 0, MPI_COMM_WORLD);
            if(finish){ break;}

            // If not finished, waits for new cluster centroids
            MPI_Bcast(&bufferSize, 1, MPI_INT, 0, MPI_COMM_WORLD);

            delete[] buffer; buffer = nullptr;

            buffer = new double[bufferSize];
            MPI_Bcast(buffer, bufferSize, MPI_DOUBLE, 0, MPI_COMM_WORLD);

            Cluster::deserializeCentroids(buffer);
        }

        // Cluster::saveCentroids(my_rank, 281);
        // Cluster::saveClusters(my_rank, 282);
    }

    MPI_Finalize();

    return 0;
}