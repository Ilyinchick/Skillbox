#include "Position.h"

int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

void Position::setX(int i) {
    this->x = i;
}

void Position::setY(int i) {
    this->y = i;
}

Position * Position::addPos(Position pos) {
    this->x += pos.x;
    this->y += pos.y;
}

