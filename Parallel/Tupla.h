#ifndef PARALLEL_TUPLA_H
#define PARALLEL_TUPLA_H

#include <string>
#include <vector>
#include <list>
using namespace std;

class Tupla{
public:
    Tupla(int dim);

    // Getter and Setter
    int get_dim();
    double get_value(int i) const;
    vector<double> get_tupla();
    void set_value(int i, double d);
    void set_tupla(const vector<double>& d);

    // Methods
    double distanza(const Tupla& t) const;
    
    string toString();

protected:
    vector<double> value;
    int dim;
};

#endif