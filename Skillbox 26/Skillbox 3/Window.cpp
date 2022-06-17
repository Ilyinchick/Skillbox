#include "Window.h"

void Window::move(Position pos) {
    Position posB = begin, posE = end;
    if (Position::isValidPosition(posB.addPos(pos)) && Position::isValidPosition(posE.addPos(pos))) {
        begin = *begin.addPos(pos);
        end = *end.addPos(pos);
    } else {
        std::cout << "Invalid position." << std::endl;
    }
}

void Window::resize(Position pos) {
    Position posB = begin;
    if (Position::isValidPosition(posB.addPos(pos))) end = posB;
    else std::cout << "Invalid position to end of window." << std::endl;
}

void Window::display() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 20; j ++) {
            if (i >= begin.getY() && i <= end.getY() && j >= begin.getX() && j <= end.getX()) std::cout << "1";
            else std::cout << "0";
        }
        std::cout << std::endl;
    }
}

void Window::setBegin(Position pos) {
    begin = pos;
}

void Window::setEnd(Position pos) {
    end = pos;
}