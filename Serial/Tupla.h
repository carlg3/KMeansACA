//
// Created by galan on 08/09/2024.
//

#ifndef TUPLA_H
#define TUPLA_H

#include <string>
#include <vector>
#include <list>
using namespace std;

class Tupla{
public:
    Tupla(int dim);

    int get_dim();
    double get_value(int i) const;
    vector<double> get_tupla();

    void set_value(int i, double d);
    void set_tupla(const vector<double>& d);

    double distanza(const Tupla& t) const;

    string toString();
protected:
    vector<double> value;
    int dim;
};

#endif