#pragma once

#include <iostream>

class Coordinate {
    double x, y;

public:
    Coordinate() {
        this->x = 0;
        this->y = 0;
    }

    Coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }

    std::string getStr();

    void setX(int x);

    void setY(int y);

    double getX();

    double getY();

};
