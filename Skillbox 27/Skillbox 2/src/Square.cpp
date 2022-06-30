#include "Square.h"

void Square::setSide(double inSide) {
    side = inSide;
}

double Square::getSide() {
    return side;
}

double Square::getSquare() {
    return std::pow(getSide(), 2);
}

void Square::print() {
    Figure::print();
    std::cout << "Square is " << getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << std::pow(getSide() + 1, 2) << "." << std::endl;
}
