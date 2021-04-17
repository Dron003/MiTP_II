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

    static void printData(const Vector& v);

    int dimension_;
private:
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

void Vector::printData() {
    for (int i = 0; i < dimension_; ++i) {
        cout << "\tdata_[" << i << "] = " << data_[i] << endl;
    }
}

void Vector::printData(const Vector& v) {
    for (int i = 0; i < v.dimension_; ++i) {
        cout << "\tvector.data_[" << i << "] = " << v.data_[i] << endl;
    }
}


int main() {
    Vector r1(1.0); // R1
    cout << "Obiekt klasy Vector o wymiarze:" << r1.dimension_ << endl;
    Vector r2(1.0,2.0); // R2
    cout << "Obiekt klasy Vector o wymiarze:" << r2.dimension_ << endl;
    Vector r3(1.0,2.5,3.1); // R3
    cout << "Obiekt klasy Vector o wymiarze:" << r3.dimension_ << endl;

    cout << "-------Zadanie 2---------" << endl;

    Vector v1(3.3,4.1);
    Vector v2(10.1,-2.1);

    v1.printData();
    v2.printData(Vector(1.1f,2.2f,3.3f));
}