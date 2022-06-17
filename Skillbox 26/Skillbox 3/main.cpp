#include <iostream>
#include "Window.h"

int main() {
    std::string command;
    int i, j;
    Window *window = new Window();

    window->setBegin(Position::createPosition(1, 1));
    window->setEnd(Position::createPosition(2, 2));

    do {
        std::cout << "Enter your command (move, resize or display): " << std::endl;
        std::cin >> command;
        if (command == "move") {
            std::cout << "Enter x for new start position: " << std::endl;
            std::cin >> i;
            std::cout << "Enter y for new start position: " << std::endl;
            std::cin >> j;
            window->move(Position::createPosition(i, j));
        } else if (command == "resize") {
            std::cout << "Enter x for new end position: " << std::endl;
            std::cin >> i;
            std::cout << "Enter y for new end position: " << std::endl;
            std::cin >> j;
            window->resize(Position::createPosition(i, j));
        } else if (command == "display") {
            window->display();
        } else if (command != "close") std::cout << "Invalid command. Try again" << std::endl;
    } while (command != "close");
    return 0;
}
