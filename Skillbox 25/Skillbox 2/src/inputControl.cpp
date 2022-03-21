#include "inputControl.h"

int enterInt() {
    std::string str;
    std::cin >> str;
    return std::stoi(str);
}

std::string enterString() {
    std::string str;
    std::cout << "Enter your command (save/load/input/display/sum/exit): " << std::endl;
    std::cin >> str;
    if (str == "save" || str == "load" || str == "sum" || str == "input" || str == "display" || str == "exit") {
        return str;
    } else {
        std::cout << "Incalid input. Try again." << std::endl;
        return enterString();
    }
}
