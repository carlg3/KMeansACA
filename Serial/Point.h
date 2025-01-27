//
// Created by galan on 08/09/2024.
//

#ifndef POINT_H
#define POINT_H

#include "Tupla.h"
using namespace std;

class Point: public Tupla{
public:
    Point(int dim);

    static Point* get_point(int index);
    static int get_spoints_();

private:
    static list<Point*> points;
};

#endif