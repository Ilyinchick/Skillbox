#include "Triangle.h"

double Triangle::getSide1() {
    return side1;
}

void Triangle::setSide1(double s) {
    side1 = s;
}

double Triangle::getSide2()  {
    return side2;
}

void Triangle::setSide2(double s) {
    side2 = s;
}

double Triangle::getSide3() {
    return side3;
}

void Triangle::setSide3(double s) {
    side3 = s;
}

double Triangle::square() {
    double p = (side1 + side2 + side3) / 2;
    return std::sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

std::string Triangle::getType() {
    return "Triangle";
}

Shape::BoundingBoxDimensions Triangle::dimensions() {
    double rad = (side1 * side2 * side3) / (4 * square());
    return BoundingBoxDimensions(rad * 2, rad * 2);
}


