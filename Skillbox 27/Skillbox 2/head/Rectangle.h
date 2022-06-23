#pragma once

#include "Figure.h"

class Rectangle: public Figure {
    double height, width;

    public:

    Rectangle(Coordinate* inCoordinate, double x, double y) {
        this->height = x;
        this->width = y;
        this->setName("Rectangle");
        this->setColor("Purple");
        this->setCoordinate(inCoordinate);
    }

    void print();

    void setHeight(double x);
    void setWidth(double y);
    double getHeight();
    double getWidth();

    double getSquare();
};

