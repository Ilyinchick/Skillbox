#include "Circle.h"

void Circle::setRaduis(double inRadius) {
    radius = inRadius;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getSquare() {
    return M_PI * std::pow(radius, 2);
}

void Circle::print() {
    Figure::print();
    std::cout << "Square is " << getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << std::pow(this->getRadius() * 2 + 1, 2) << "." << std::endl;
}
