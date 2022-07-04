#pragma once
#include "Shape.h"

class Triangle: public Shape {

    double side1, side2, side3;
public:
    double getSide1();

    void setSide1(double side1);

    double getSide2();

    void setSide2(double side2);

    double getSide3();

    void setSide3(double side3);

    double square();

    std::string getType();

    BoundingBoxDimensions dimensions();

    Triangle(double s1, double s2, double s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
};

