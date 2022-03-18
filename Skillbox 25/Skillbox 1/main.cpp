#include <iostream>
#include "my-head.h"

int main() {
    coordinate start, finish, dummy, startSut, finishSut;
    std::string command;

    std::cout << "Type 'scalpel' to start." << std::endl;
    command = input("scalpel");
    std::cout << "Enter point to start cut: " << std::endl;
    start.init();
    std::cout << "Enter point to finish cut: " << std::endl;
    finish.init();

    scalpel(start, finish);

    while (!(isEqual(start, startSut) && isEqual(finish, finishSut))) {
        std::cout << "Enter your command: " << std::endl;
        std::cin >> command;
        if (command == "hemostat") {
            std::cout << "Enter point to hemostat: " << std::endl;
            dummy.init();
            hemostat(dummy);
        } else if (command == "tweezers") {
            std::cout << "Enter point to tweezers: " << std::endl;
            dummy.init();
            tweezers(dummy);
        } else if (command == "suture") {
            std::cout << "Enter point to start suture: " << std::endl;
            startSut.init();
            std::cout << "Enter point to finish suture: " << std::endl;
            finishSut.init();
            suture(startSut, finishSut);
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }

    std::cout << "You completed operation. Congratulations!" << std::endl;

    return 0;
}


