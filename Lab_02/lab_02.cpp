//
// Created by danilkov on 17.04.21.
//

#include <iostream>

class Circle {
public:
    Circle() = default;
    Circle(float radius)  {
        std::cout << "Alokacja pamieci dla radius_" << std::endl;
        radius_ = new float;
        *radius_ = radius;
    }

    virtual ~Circle() {
        std::cout << "Zwolnienie pamieci dla radius_" << std::endl;
        delete radius_;
    }

    float* radius_;
};

int main() {
    // Pod czas deklarowania circle1 wystąpi błąd, bo zmieniliśmy typ radius_
    /*Circle circle1;
    circle1.radius_ = 2.0f;*/

    Circle circle2(3.0f);
}