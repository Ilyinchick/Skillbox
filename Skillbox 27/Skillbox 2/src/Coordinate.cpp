#include "Coordinate.h"

std::string Coordinate::getStr() {
    std::string coordinate = "( " + std::to_string(getX()) + " : " + std::to_string(getY()) + " )";
    return coordinate;
}

void Coordinate::setX(int inX) {
    x = inX;
}

void Coordinate::setY(int inY) {
    y = inY;
}

double Coordinate::getX() {
    return x;
}

double Coordinate::getY() {
    return y;
}
