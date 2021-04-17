
#include <iostream>

class Circle {
public:
    explicit Circle(float radius);
    // explicit zabrania kompilatoru niejawnie konwertowac typy dla konstruktora
    float circumference() const;
    float area() const;

private:
    constexpr static float PI = 3.14159265359f;
    /* constexpr - wartosc zmiennej wiadoma pod czas kompilacji
     * static    - zmienna nie bedzie tworzona dla kazdego objectu Circle oddzielnie. Bedzie wspolna dla wszystkich */
    float radius_;
    float area_;
public:
    float getRadius() const;

    void setRadius(float radius);

private:
    float circumference_;
};

float Circle::circumference() const {
    return 2 * PI * radius_;
}

float Circle::area() const {
    return PI * radius_ * radius_;
}

Circle::Circle(float radius) : radius_{radius}, area_{area()}, circumference_{circumference()} {

}

float Circle::getRadius() const {
    return radius_;
}

void Circle::setRadius(float radius) {
    radius_ = radius;
}

int main () {
    Circle circle(3.5f);
    std::cout << "Radius ustawiony w liscie inicjalizujacej: " << circle.getRadius() << std::endl;
    circle.setRadius(12.0f);
    std::cout << "Radius zmieniony za pomoca settera: " << circle.getRadius() << std::endl;
    std::cout << "Obwod: " << circle.circumference() << std::endl;
    std::cout << "Powierzchnia: " << circle.area() << std::endl;
}