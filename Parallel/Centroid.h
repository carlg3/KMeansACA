#ifndef PARALLEL_CENTROID_H
#define PARALLEL_CENTROID_H

#include "Tupla.h"
using namespace std;

class Centroid: public Tupla{
public:
    Centroid(int dim);

    // Getters
    static Centroid* get_centroid(int index);
    static int get_scentroids_();

private:
    static list<Centroid*> centroids;
};

#endif