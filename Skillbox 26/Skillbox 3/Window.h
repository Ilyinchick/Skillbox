#pragma once

#include "Position.h"
#include <iostream>

class Window {

    Position begin;
    Position end;

public:
    void move(Position pos);

    void resize(Position pos);

    void display();

    void setBegin(Position pos);

    void setEnd(Position pos);
};
