#include <iostream>
#include <stdio.h>

using namespace std;

class Vector {
public:
    Vector() = delete;

    Vector(double);

    Vector(double element1, double element2);

    Vector(double element1, double element2, double element3);


    void printData();

    int dimension_;

    double data_[3] = {0, 0, 0};
};

Vector::Vector(double element1) {
    cout << "\nTworzenie obiektu klasy Vector w przestrzeni R1 :" << endl;
    dimension_ = 1;
    data_[0] = element1;
}

Vector::Vector(double element1, double element2) {
    cout << "\nTworzenie obiektu klasy Vector w przestrzeni R2 :" << endl;
    dimension_ = 2;
    data_[0] = element1;
    data_[1] = element2;
}

Vector::Vector(double element1, double element2, double element3) {
    cout << "\nTworzenie obiektu klasy Vector w przestrzeni R3 :" << endl;
    dimension_ = 3;
    data_[0] = element1;
    data_[1] = element2;
    data_[2] = element3;
}

Vector operator+(const Vector &lhs, const Vector &rhs) {
    return Vector(lhs.data_[0] + rhs.data_[0],
                  lhs.data_[1] + rhs.data_[1],
                  lhs.data_[2] + rhs.data_[2]);
}

void Vector::printData() {
    for (int i = 0; i < dimension_; ++i) {
        cout << "\tdata_[" << i << "] = " << data_[i] << endl;
    }
}

int main() {
    Vector v1(1.0f, 1.0f, 1.0f);
    Vector v2(2.0f, -2.0f, 0.0f);

    Vector v3 = v1 + v2;

    v3.printData();
}