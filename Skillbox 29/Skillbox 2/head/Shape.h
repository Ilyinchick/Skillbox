#pragma once

#include <iostream>
#include <cmath>

class Shape {
public:

    struct BoundingBoxDimensions {
        BoundingBoxDimensions(double a, double b) {
            x = a;
            y = b;
        }
        double x, y;
    };

    virtual double square() = 0;

    virtual std::string getType() = 0;

    virtual BoundingBoxDimensions dimensions() = 0;

    static void printParams(Shape *shape) {
        std::cout << shape->getType() << ": " << std::endl;
        std::cout << "Square is " << shape->square() << std::endl;
        std::cout << "Bounding box dimensions is " << shape->dimensions().x << " and " << shape->dimensions().y << std::endl;
    }



};