#include "Figure.h"

void Figure::setColor(std::string inColor) {
    this->color = inColor;
}

void Figure::setCoordinate(Coordinate *inCoordinate) {
    this->coordinate = *inCoordinate;
}

std::string Figure::getColor() {
    return this->color;
}

Coordinate *Figure::getCoordinate() {
    return &this->coordinate;
}

void Figure::print() {
    std::cout << "\n" << this->getName() << ": " << this->getCoordinate()->getStr() << " " << this->getColor() << "." << std::endl;
}

void Figure::setName(std::string inName) {
    this->name = inName;
}

std::string Figure::getName() {
    return this->name;
}
