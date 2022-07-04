#include "Rectangle.h"

void Rectangle::setHeight(double h) {
    height = h;
}

void Rectangle::setWidth(double w) {
    width = w;
}

double Rectangle::getHeight() {
    return height;
}

double Rectangle::getWidth() {
    return width;
}

double Rectangle::square() {
    return height * width;
}

std::string Rectangle::getType() {
    return "Rectangle";
}

Shape::BoundingBoxDimensions Rectangle::dimensions() {
    return Shape::BoundingBoxDimensions(height + 1, width + 1);
}
