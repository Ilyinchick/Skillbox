#include "Triangle.h"

void Triangle::setSide(double inSide) {
    side = inSide;
}

double Triangle::getSide() {
    return side;
}

double Triangle::getSquare() {
    return std::pow(getSide(), 2) * std::sqrt(3) / 4;
}

void Triangle::print() {
    Figure::print();
    std::cout << "Square is " << getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << std::pow(getSide() + 1, 2) << "." << std::endl;
}
