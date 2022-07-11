#pragma once

#include <iostream>

class Toy {
private:
    std::string name;

public:

    Toy() {}

    Toy(std::string _name) : name(_name) {}

    Toy(Toy* oth) : name(oth->name) {}
};

