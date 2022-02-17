#include <iostream>
#include <string>

int enterNumber();

int main() {
    float number;
    char strNum[100];

    std::cout << "Enter before dot and after dot parts: " << std::endl;
    int first = enterNumber(), second = enterNumber();

    std::sprintf(strNum, "%i.%i", first, second);
    number = std::strtof(strNum, nullptr);

    std::cout << number;
    return 0;
}

int enterNumber() {
    int number;
    std::cin >> number;
    return number;
}
