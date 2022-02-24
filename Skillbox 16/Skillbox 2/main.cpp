#include <iostream>
#include <string>

double enterBeforeDot();

double enterAfterDot();

int main() {
    double number;

    std::cout << "Enter before dot and after dot parts: " << std::endl;

    number = enterBeforeDot();
    number += enterAfterDot();

    std::cout << number;
    return 0;
}

double enterBeforeDot() {
    std::string in;
    std::getline(std::cin, in);
    double num = std::stod(in);
    return num;
}

double enterAfterDot() {
    std::string in = ".", dummy;
    std::getline(std::cin, dummy);
    in += dummy;
    double num = std::stod(in);
    return num;
}
