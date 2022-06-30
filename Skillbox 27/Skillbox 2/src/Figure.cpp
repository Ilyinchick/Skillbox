#include "Figure.h"

void Figure::setColor(std::string inColor) {
    color = inColor;
}

void Figure::setCoordinate(Coordinate *inCoordinate) {
    coordinate = *inCoordinate;
}

std::string Figure::getColor() {
    return color;
}

Coordinate *Figure::getCoordinate() {
    return &coordinate;
}

void Figure::print() {
    std::cout << "\n" << this->getName() << ": " << getCoordinate()->getStr() << " " << getColor() << "." << std::endl;
}

void Figure::setName(std::string inName) {
    name = inName;
}

std::string Figure::getName() {
    return name;
}
