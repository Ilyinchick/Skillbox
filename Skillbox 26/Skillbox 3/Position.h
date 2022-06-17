#pragma once

#include <iostream>

class Position {
    int x;
    int y;

public:
    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

    Position * addPos(Position pos);

    static bool isValidPosition(Position* pos) {
        if (pos->x >= 0 && pos->x <= 20 && pos->y >= 0 && pos->y <= 5) return true;
        else return false;
    }

    static Position createPosition(int i, int j) {
        Position *pos = new Position();
        pos->setX(i);
        pos->setY(j);
        return *pos;
    }
};

