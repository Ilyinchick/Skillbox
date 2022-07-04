#include "Dog.h"

void Dog::addSwimming() {
    Swimming::addTalent(&talents);
}

void Dog::addDancing() {
    Dancing::addTalent(&talents);
}

void Dog::addCounting() {
    Counting::addTalent(&talents);
}

void Dog::showTalents() {
    for (std::string s: talents) {
        std::cout << "It can " << s << "." << std::endl;
    }
}

