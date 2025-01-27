//
// Created by galan on 08/09/2024.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <random>

#include "Cluster.h"
#include "Point.h"

#include <chrono>
using namespace chrono;
using namespace std;

int MAX_ITER = 10;

// string path_gcloud = "/home/galan/ACAproject/MPI-K-Means-Clustering-main/";
string path_gcloud = "/mnt/c/Users/galan/Documents/GitHub/ACAproject/MPI-K-Means-Clustering-main/";

string dataset = path_gcloud + "DataSet/DataSet10000x10.txt";

void readDataset(vector<Point*>& points, const string& filePath){
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
        for (int i = 0; i < (int)elems.size(); i++) {
            point->set_value(i, stod(elems[i]));
        }

        points.push_back(point);
    }

    dataset.close();
}

int main(int argc, char* argv[]) {
    auto start = high_resolution_clock::now(); // Inizia il timer

    vector<Point*> points_temp_;

	// Reading dataset..
	if(argc == 2){
		dataset = path_gcloud + "DataSet/" + argv[1];
	}
    readDataset(points_temp_, dataset);
   
    int point_dim = points_temp_[0]->get_dim();
    int points_number = points_temp_.size();

	int K = sqrt(points_number/2);

    Cluster::create_clusters(K, point_dim);

    double precTMSE = 0, tmse = 0;

    while (true) {
        Cluster::reset_clusters();

        Cluster::map_point_to_cluster();

        Cluster::find_centroid_clusters();

        precTMSE = tmse;
        tmse = Cluster::tMSE();

        printf("MAX_ITER: %d, tmse: %f, precTMSE: %f\n",MAX_ITER, tmse, precTMSE);
        if(!(--MAX_ITER && ((tmse < precTMSE) || precTMSE == 0))){break;}
    }

    // Using chrono to get time spent
    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(end - start).count(); // Tempo in microsecondi

    // cout << "That took " << duration*1e-6 << " seconds" << endl;
    cout << duration*1e-6 << endl;

    // [DEBUG] Per salvare i cluster e centroidi su file
    // Cluster::saveCentroids(0, 118);
    // Cluster::saveClusters(0, 110);

    return 0;
}