//
// Created by galan on 08/09/2024.
//

#ifndef CENTROID_H
#define CENTROID_H

#include "Tupla.h"
using namespace std;

class Centroid: public Tupla{
public:
    Centroid(int dim);

    static Centroid* get_centroid(int index);
    static int get_scentroids_();
private:
    static list<Centroid*> centroids;
};

#endif