#include <iostream>
#include <cmath>

using namespace std;

class Vector {
public:
    Vector() = delete;

    Vector(double);

    Vector(double element1, double element2);

    Vector(double element1, double element2, double element3);

    const double *getData() const;

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

const double *Vector::getData() const {
    return data_;
}

float count_length(const double *data) {
    return sqrt(pow(data[0], 2) + pow(data[1], 2) + pow(data[2], 2));
}

float count_length(const Vector &vector) {
    return sqrt(pow(vector.getData()[0], 2) + pow(vector.getData()[1], 2) + pow(vector.getData()[2], 2));
}

int main() {
    Vector v1(1.0f, 2.0f, 3.0f);
    std::cout << "Moduł vectora: " << count_length(v1.getData()) << endl;

    Vector v2(1.0f, 2.0f, 3.0f);
    /* "Druga metoda powinna:
...
być wywoływana obiektem typu Vector"
W tresci zadania napisano, ze to mają byc funkcje, a nie metody klasy Vector.
Jak funkcja moze byc wywolana objektem Vector, jezeli nie funkcja nie jest metoda Vector?

*/
    std::cout << "Moduł vectora: " << count_length(v2);

    /* 1. W kodzie z poprzedniego z zadania 3 zmień specyfikator dostępu składowej data_ z powrotem na private .
       2. Uruchom kod. Dlaczego wystąpił błąd?
       O: Błąd wystąpił bo nie ma dostępu do prywatnych skladowych poza klasą / metodami klasy */

}