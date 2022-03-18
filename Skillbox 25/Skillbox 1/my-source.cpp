#include "my-head.h"

void scalpel(coordinate x, coordinate y) {
    std::cout << "Cut was made between points " << x.print() << " and " << y.print() << "." << std::endl;
}

void hemostat(coordinate x) {
    std::cout << "Hemostat has been applied to a point " << x.print() << std::endl;
}

void tweezers(coordinate x) {
    std::cout << "Tweezers have been applied to a point " << x.print() << std::endl;
}

void suture(coordinate x, coordinate y) {
    std::cout << "Suture has been placed between points " << x.print() << " and " << y.print() << "." << std::endl;
}

bool isEqual(coordinate x, coordinate y) {
    if (x.x == y.x && x.y == y.y) return true;
    else return false;
}

std::string input(std::string expected) {
    std::string str;
    std::cin >> str;
    if (str != expected) {
        std::cout << "Ivalid input. Type again:" << std::endl;
        input(expected);
    } else return str;
}