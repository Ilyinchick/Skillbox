#pragma once

#include "Figure.h"

class Triangle: public Figure {
    double side;

public:
    Triangle(Coordinate* inCoordinate, double inSide) {
        this->setName("Triangle");
        this->setCoordinate(inCoordinate);
        this->side = inSide;
        this->setColor("blue");
    }

    void setSide(double side);
    double getSide();
    double getSquare();
    void print();
};
