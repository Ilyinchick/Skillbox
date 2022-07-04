#pragma once

#include "Shape.h"

class Rectangle: public Shape {
    double height, width;

public :
    void setHeight(double h);

    void setWidth(double w);

    double getHeight();

    double getWidth();

    virtual double square();

    virtual std::string getType();

    virtual BoundingBoxDimensions dimensions();

    Rectangle(double h, double w) {
        height = h;
        width = w;
    }
};
