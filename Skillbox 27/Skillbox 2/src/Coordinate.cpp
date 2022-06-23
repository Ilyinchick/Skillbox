#include "Coordinate.h"

std::string Coordinate::getStr() {
    std::string coordinate = "( " + std::to_string(this->getX()) + " : " + std::to_string(this->getY()) + " )";
    return coordinate;
}

void Coordinate::setX(int inX) {
    this->x = inX;
}

void Coordinate::setY(int inY) {
this->y = inY;
}

double Coordinate::getX() {
    return this->x;
}

double Coordinate::getY() {
    return this->y;
}
