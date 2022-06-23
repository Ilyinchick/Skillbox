#pragma once

#include "Figure.h"

class Square : public Figure {
    double side;

public:
    Square(Coordinate* inCoordinate, double inSide) {
        this->setName("Square");
        this->setColor("green");
        this->setCoordinate(inCoordinate);
        this->side = inSide;
    }

    void setSide(double side);

    double getSide();

    double getSquare();

    void print();
};
