#ifndef PARALLEL_CLUSTER_H
#define PARALLEL_CLUSTER_H

#include "Centroid.h"
#include "Point.h"
using namespace std;

class Cluster{
public:
    Cluster(int centroid_dim_);

    // Getters and Setters
    static Cluster* get_cluster(int index);
    static int get_sclusters_();
	int get_selements_();
    Centroid* get_centroid();
    Point* get_point(int index);
    list<Point*> get_lpoints_();

    double get_sum_coords_cluster(int index);
    void set_selements_(int num);
    void setSumCoordsCluster(int index, double value);
    static double getSumPointsDistance();
    static void setSumPointsDistance(double value);

    // Methods
    static void create_clusters(int K, int centroid_dim);
    void create_centroid(int centroid_dim);

    void empty_cluster();
    static void reset_clusters();
    void init_sum_coords();
    void add_point(Point *t);

    static void map_point_to_cluster(int startIndex = 0, int endIndex = Point::get_spoints_());
    void sum_points_();
    static void sum_points_clusters();
    void find_centroid_();
    static void find_centroid_clusters();
    static double tMSE();
    
    // Serialization functions
    static void serializeCluster(double* buffer);
    static void deserializeCluster(double* buffer);
    static void serializeCentroids(double* buffer);
    static void deserializeCentroids(double* buffer);
    static void serializeSumCoordsCluster(double* buffer);
    static void deserializeSumCoordsCluster(double* buffer);

    // Debug
    static void saveClusters(int my_rank, int bp);
    static void saveCentroids(int my_rank, int bp);

private:
    static list<Cluster*> clusters;
    static double sum_points_distance_; // di ogni punto del dataset dal 'suo' centroide su _tutti_ i cluster

    double *sum_coords_cluster_;    // somma vettoriale di ogni punto di _questo_ cluster

    list<Point*> cluster_points_;   // punti di _questo_ cluster
    int points_number_;             // numero dei punti

    Centroid *centroid;
};

#endif