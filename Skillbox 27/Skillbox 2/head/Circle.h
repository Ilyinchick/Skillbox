#pragma once

#include "Figure.h"

class Circle : public Figure {
    double radius;

public:

    Circle(Coordinate *inCoordinate, double inRadius) {
        this->setColor("red");
        this->setName("Circle");
        this->setCoordinate(inCoordinate);
        this->radius = inRadius;
    }

    void setRaduis(double inRadius);

    double getRadius();

    double getSquare();

    void print();
};
