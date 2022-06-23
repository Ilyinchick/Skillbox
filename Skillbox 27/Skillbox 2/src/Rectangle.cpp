#include "Rectangle.h"

void Rectangle::print() {
    Figure::print();
    std::cout << "Square is " << this->getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << (this->getWidth() + 1) * (this->getHeight() + 1) << "." << std::endl;
}

double Rectangle::getSquare() {
    return this->getHeight() * this->getWidth();
}

void Rectangle::setHeight(double x) {
    this->height = x;
}

void Rectangle::setWidth(double y) {
    this->width = y;
}

double Rectangle::getHeight() {
    return this->height;
}

double Rectangle::getWidth() {
    return this->width;
}
