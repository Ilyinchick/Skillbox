#include "Square.h"

void Square::setSide(double inSide) {
    this->side = inSide;
}

double Square::getSide() {
    return this->side;
}

double Square::getSquare() {
    return std::pow(this->getSide(), 2);
}

void Square::print() {
    Figure::print();
    std::cout << "Square is " << this->getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << std::pow(this->getSide() + 1, 2) << "." << std::endl;
}
