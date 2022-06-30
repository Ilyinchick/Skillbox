#include "Rectangle.h"

void Rectangle::print() {
    Figure::print();
    std::cout << "Square is " << getSquare() << "." << std::endl;
    std::cout << "Square of circumscribing rectangle is " << (getWidth() + 1) * (getHeight() + 1) << "." << std::endl;
}

double Rectangle::getSquare() {
    return getHeight() * this->getWidth();
}

void Rectangle::setHeight(double x) {
    height = x;
}

void Rectangle::setWidth(double y) {
    width = y;
}

double Rectangle::getHeight() {
    return height;
}

double Rectangle::getWidth() {
    return width;
}
