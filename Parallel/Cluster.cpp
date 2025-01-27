#include <iostream>
#include <fstream>

#include "Tupla.h"
#include "Cluster.h"
using namespace std;

double Cluster::sum_points_distance_;
list<Cluster*> Cluster::clusters;

// Crea un cluster e gli assegna un centroide
Cluster::Cluster(int centroid_dim_){
    clusters.push_back(this);

    create_centroid(centroid_dim_);

    Cluster::sum_points_distance_ = 0;

    sum_coords_cluster_ = new double[centroid_dim_];
    init_sum_coords();

    points_number_ = 0;
}

// ---- GETTERS & SETTERS ----
list<Point*> Cluster::get_lpoints_() {
    return cluster_points_;
};

Centroid* Cluster::get_centroid(){
    return centroid;
}

Point* Cluster::get_point(int index) {
    auto it = cluster_points_.begin();
    advance(it, index);
    return *it;
}

Cluster* Cluster::get_cluster(int index){
    auto it = clusters.begin();
    advance(it, index);
    return *it;
}

int Cluster::get_sclusters_(){
    return clusters.size();
}

int Cluster::get_selements_(){
    return points_number_;
}

double Cluster::get_sum_coords_cluster(int index){
    return sum_coords_cluster_[index];
}

double Cluster::getSumPointsDistance(){
    return Cluster::sum_points_distance_;
}

void Cluster::set_selements_(int num){
    points_number_ = num;
}

void Cluster::setSumCoordsCluster(int index, double value){
    sum_coords_cluster_[index] = value;
}

void Cluster::setSumPointsDistance(double value){
    Cluster::sum_points_distance_ = value;
}

void Cluster::empty_cluster(){
    cluster_points_.clear();
    points_number_ = 0;

    Cluster::sum_points_distance_ = 0;
    init_sum_coords();
}

// ------ METHODS ------
void Cluster::reset_clusters(){
    for(int i = 0; i < Cluster::get_sclusters_(); i++){
        Cluster::get_cluster(i)->empty_cluster();
    }
}

void Cluster::create_clusters(int K, int centroid_dim_){
    for(int i = 0; i < K; i++){
        new Cluster(centroid_dim_);
    }
}

void Cluster::create_centroid(int centroid_dim_){
    centroid = new Centroid(centroid_dim_);

    // [TEST Correttezza] Per generare con un seed fisso, quindi prende sempre stessi punti
    srand(42);

    int centroid_index = rand() % (Point::get_spoints_() - 1);

    // Prende un punto random tra i punti e lo setta come centroide
    centroid->set_tupla(Point::get_point(centroid_index)->get_tupla());
}

void Cluster::add_point(Point *t){
    cluster_points_.push_back(t);

    points_number_++;
}

void Cluster::init_sum_coords() {
    int centroid_dim_ = centroid->get_dim();

    for(int i = 0; i < centroid_dim_; i++){
        sum_coords_cluster_[i] = 0;
    }
}

void Cluster::sum_points_(){
    init_sum_coords();

    int centroid_dim_ = centroid->get_dim();

    for(int i = 0; i < points_number_; i++){
        for(int j = 0; j < centroid_dim_; j++){
            sum_coords_cluster_[j] += get_point(i)->get_value(j);
        }
    }
}

void Cluster::sum_points_clusters(){
    int cluster_number_ = Cluster::get_sclusters_();

    for(int i = 0; i < cluster_number_; i++){
        Cluster::get_cluster(i)->sum_points_();
    }
}

/*
* Ritorna la MeanSquaredError cioè la somma delle distanze minime dei <punti>
* dei <Cluster> (con il loro corrispondente <centroide>) diviso il numero totale dei punti
*/
double Cluster::tMSE(){
    return Cluster::sum_points_distance_/Point::get_spoints_();
}

// ----- MAP -----
void Cluster::map_point_to_cluster(int startIndex, int endIndex) {
    for (int i = startIndex; i < endIndex; i++) {
        double min_dist = Point::get_point(i)->distanza(*clusters.front()->get_centroid());
        Cluster* closestCluster = clusters.front();

        bool isFirst = true;
        for (auto cluster : clusters) {
            if (isFirst) {
                isFirst = false;
                continue; // Salta il primo elemento
            }
            double distance = Point::get_point(i)->distanza(*cluster->get_centroid());

            if (distance < min_dist) {
                min_dist = distance;
                closestCluster = cluster;
            }
        }

        closestCluster->add_point(Point::get_point(i));
        Cluster::sum_points_distance_ += min_dist;
    }
}

void Cluster::find_centroid_(){
    double mean;
    int centroid_dim = centroid->get_dim();

    // printf("points_number_: %d\n", points_number_);

    if(points_number_){
        for(int i = 0; i < centroid_dim; i++){
            mean = sum_coords_cluster_[i]/points_number_;
            centroid->set_value(i, mean);
        }
    }else{
        for(int i = 0; i < centroid_dim; i++) {
            centroid->set_value(i,0);
        }
    }
}

void Cluster::find_centroid_clusters(){
    for(int i = 0; i < Cluster::get_sclusters_(); i++){
        Cluster::get_cluster(i)->find_centroid_();
    }
}

// ----- SERIALIZING FUNCTIONS -----
// Invia solo i centroidi per ogni cluster
void Cluster::serializeCentroids(double* buffer){
    int K = Cluster::get_sclusters_();
    int dim = Cluster::get_cluster(0)->get_centroid()->get_dim();

    for(int i = 0; i < K; i++){
        for(int j = 0; j < dim; j++){
            buffer[i * dim + j] = Cluster::get_cluster(i)->get_centroid()->get_value(j);
        }
    }
}

void Cluster::deserializeCentroids(double* buffer) {
    int K = Cluster::get_sclusters_();
    int dim = Cluster::get_cluster(0)->get_centroid()->get_dim();

    for(int i = 0; i < K; i++){
        for(int j = 0; j < dim; j++){
            Cluster::get_cluster(i)->get_centroid()->set_value(j, buffer[i * dim + j]);
        }
    }
}

// Invia numero di cluster e la dimensione dei punti, poi i centroidi per ogni cluster
void Cluster::serializeCluster(double* buffer){
    int K = Cluster::get_sclusters_();
    int dim = Cluster::get_cluster(0)->get_centroid()->get_dim();

    buffer[0] = K; // Number of clusters
    buffer[1] = dim; // Centroid dimension

    Cluster::serializeCentroids(buffer + 2);
}

void Cluster::deserializeCluster(double* buffer) {
    int K = buffer[0];
    int dim = buffer[1]; // Point dimension

    Cluster::create_clusters(K, dim);

    Cluster::deserializeCentroids(buffer + 2);
}

void Cluster::serializeSumCoordsCluster(double *buffer){
    int cluster_number_ = Cluster::get_sclusters_();
    int dim = Cluster::get_cluster(0)->get_centroid()->get_dim();
    int index;

    for(int i = 0; i < cluster_number_; i++){
        index = i * (dim + 1);

        for(int j = 0; j < dim; j++){
            buffer[index + j] = Cluster::get_cluster(i)->get_sum_coords_cluster(j);
        }

        buffer[index + dim] = Cluster::get_cluster(i)->get_selements_();
    }
}

void Cluster::deserializeSumCoordsCluster(double *buffer) {
    int cluster_number_ = Cluster::get_sclusters_();
    int dim = Cluster::get_cluster(0)->get_centroid()->get_dim();
    int index;

    for(int i = 0; i < cluster_number_; i++) {
        index = i * (dim + 1);

        for (int j = 0; j < dim; j++) {
            Cluster::get_cluster(i)->setSumCoordsCluster(j, buffer[index + j]);
        }

        Cluster::get_cluster(i)->set_selements_(buffer[index + dim]);
    }
}

// ---- DEBUG ----
void Cluster::saveClusters(int my_rank, int bp){
    // Creo path del file
    string file = to_string(bp) + "_clusters_rank_"; file.append(std::to_string(my_rank)); file.append(".txt");
    ofstream f(file);

    f<<"// RANK = "<<my_rank<<'\n';

    for(int i = 0; i < get_sclusters_(); i++) {
        for(int j = 0; j < get_cluster(i)->get_lpoints_().size(); j++){
            f << i << ';' <<  get_cluster(i)->get_point(j)->toString().c_str() << "\n";
        }
    }

    f.close();
}

void Cluster::saveCentroids(int my_rank, int bp){
    // Creo path del file a quel BreakPoint fittizio
    string file = to_string(bp) + "_centroids_rank_"; file.append(std::to_string(my_rank)); file.append(".txt");
    ofstream f(file);

    for (int i = 0; i < get_sclusters_(); i++) {
        f << i << ";" << get_cluster(i)->get_centroid()->toString() << endl;
    }

    f.close();
}