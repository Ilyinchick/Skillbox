#pragma once

#include <iostream>

struct coordinate {
    double x, y;

    std::string print() {
        return "(" + std::to_string(x) + ":" + std::to_string(y) + ")";
    }

    void init() {
        std::cout << "Enter x-value: ";
        std::cin >> x;
        std::cout << "\nEnter y-value: ";
        std::cin >> y;
        std::cout << std::endl;
    }
};

void scalpel(coordinate x, coordinate y);

void hemostat(coordinate x);

void tweezers(coordinate x);

void suture(coordinate x, coordinate y);

bool isEqual(coordinate x, coordinate y);

std::string input(std::string expected);
