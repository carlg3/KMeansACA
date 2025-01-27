#include "Tupla.h"
using namespace std;

Tupla::Tupla(int dim) : dim(dim), value(dim) {}

double Tupla::distanza(const Tupla& t) const {
    double diff, result = 0;
    for (int i = 0; i < dim; i++) {
        diff = get_value(i) - t.get_value(i);
        result += diff * diff;
    }
    return result;
}

double Tupla::get_value(int i) const {
    return value.at(i);
}

vector<double> Tupla::get_tupla(){
    return value;
}

void Tupla::set_value(int i, double d) {
    value.at(i) = d;
}

void Tupla::set_tupla(const vector<double>& d) {
    value = d;
}

int Tupla::get_dim() {
    return dim;
}

string Tupla::toString() {
    string s = "(";
    for (int i = 0; i < dim; i++) {
        if (i == 0) {
            s += to_string(value.at(i));
        } else {
            s += "," + to_string(value.at(i));
        }
    }
    return s + ")";
}