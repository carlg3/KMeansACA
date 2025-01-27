//
// Created by galan on 08/09/2024.
//

#include <iostream>
#include <fstream>

#include "Tupla.h"
#include "Cluster.h"
using namespace std;

double Cluster::sum_points_distance_;
list<Cluster*> Cluster::clusters;

Cluster::Cluster(const int centroid_dim_) {
    clusters.push_back(this);

    create_centroid(centroid_dim_);
}

// Getters and Setters
void Cluster::set_centroid(int index, double value) {
    centroid->set_value(index, value);
}

Centroid* Cluster::get_centroid() {
    return centroid;
}

Point* Cluster::get_point(int index) {
    auto it = cluster_points_.begin();
    advance(it, index);
    return *it;
}

Cluster* Cluster::get_cluster(const int index) {
    auto it = clusters.begin();
    advance(it, index);
    return *it;
}

int Cluster::get_sclusters_() {
    return clusters.size();
}

int Cluster::get_spoints_() {
    return cluster_points_.size();
}

// Methods
void Cluster::empty_cluster() {
    cluster_points_.clear();

    sum_points_distance_ = 0;
}

void Cluster::reset_clusters() {
    for (auto cluster : clusters) {
        cluster->empty_cluster();
    }
}

void Cluster::create_clusters(int K, int centroid_dim) {
    for (int i = 0; i < K; i++) {
        new Cluster(centroid_dim);
    }
}

void Cluster::create_centroid(int centroid_dim_) {
    centroid = new Centroid(centroid_dim_);

    // [TEST Correttezza] Per generare con un seed fisso, quindi prende sempre stessi punti
    srand(42);

    // Prende un punto random tra i punti e lo setta come centroide
    int centroid_index = rand() % (Point::get_spoints_() - 1);

    centroid->set_tupla(Point::get_point(centroid_index)->get_tupla());
}

void Cluster::add_point(Point* t) {
    cluster_points_.push_back(t);
}

void Cluster::map_point_to_cluster() {
    for (int i = 0; i < Point::get_spoints_(); i++) {
        double min_dist = Point::get_point(i)->distanza(*clusters.front()->get_centroid());
        Cluster* closestCluster = clusters.front();

        bool isFirst = true;
        for (auto cluster : clusters){
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

void Cluster::find_centroid_clusters() {
    for (auto cluster : clusters) {
        cluster->find_centroid_();
    }
}

void Cluster::find_centroid_() {
    int centroid_dim = centroid->get_dim();

    // printf("points_number_: %d\n", (int) cluster_points_.size());

    if (!cluster_points_.empty()) {
        for (int i = 0; i < centroid_dim; i++) {
            centroid->set_value(i, mean(i));
        }
    }
    else {
        for (int i = 0; i < centroid_dim; i++) {
            centroid->set_value(i, 0);
        }
    }
}

double Cluster::mean(int index) {
    double sum = 0;
    for (auto point : cluster_points_) {
        sum += point->get_value(index);
    }
    return sum / (int) cluster_points_.size();
}

double Cluster::tMSE() {
    return sum_points_distance_ / Point::get_spoints_();
}

// Debug
void Cluster::saveClusters(int my_rank, int bp) {
    // Creo path del file
    string file = to_string(bp) + "_clusters_rank_"; file.append(std::to_string(my_rank)); file.append(".txt");
    ofstream f(file);

    for (int i = 0; i < Cluster::get_sclusters_(); i++) {
        for (int j = 0; j < Cluster::get_cluster(i)->get_spoints_(); j++) {
            f << i << ";" << Cluster::get_cluster(i)->get_point(j)->toString() << endl;
        }
    }

    f.close();
}

void Cluster::saveCentroids(int my_rank, int bp) {
    // Creo path del file a quel BreakPoint fittizio
    string file = to_string(bp) + "_centroids_rank_"; file.append(std::to_string(my_rank)); file.append(".txt");
    ofstream f(file);

    for (int i = 0; i < Cluster::get_sclusters_(); i++) {
        f << i << ";" << Cluster::get_cluster(i)->get_centroid()->toString() << endl;
    }

    f.close();
}