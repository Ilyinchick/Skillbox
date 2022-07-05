#include <iostream>
#include "cpr/cpr.h"

void doCommand(std::string command) {
    if (command == "get") std::cout << cpr::Get(cpr::Url("httpbin.org/get")).text << std::endl;
    else if (command == "post") std::cout << cpr::Post(cpr::Url("httpbin.org/post")).text << std::endl;
    else if (command == "put") std::cout << cpr::Put(cpr::Url("httpbin.org/put")).text << std::endl;
    else if (command == "delete") std::cout << cpr::Delete(cpr::Url("httpbin.org/delete")).text << std::endl;
    else if (command == "patch") std::cout << cpr::Patch(cpr::Url("httpbin.org/patch")).text << std::endl;
    else std::cout << "Invalid command. Try again." << std::endl;
}

int main() {
    std::string command;
    while (command != "exit") {
        std::cout << "Enter your command: " << std::endl;
        std::cin >> command;
        if (command != "exit") doCommand(command);
    }

    return 0;
}
