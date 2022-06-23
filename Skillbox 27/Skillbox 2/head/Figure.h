#pragma once

#include "Coordinate.h"
#include <cmath>

class Figure {
    Coordinate coordinate;
    std::string color;
    std::string name;


public:
    Figure() {
        this->color = "none";
        this->name = "unnamed";
    }

    void setColor(std::string color);

    void setCoordinate(Coordinate *coordinate);

    void setName(std::string name);

    std::string getColor();

    Coordinate *getCoordinate();

    std::string getName();

    void print();
};
