#pragma once

#include "Shape.h"

class Circle : public Shape {
    double radius;

public:

    double square();

    std::string getType();

    BoundingBoxDimensions dimensions();

    Circle(double rad) {
        radius = rad;
    }
};