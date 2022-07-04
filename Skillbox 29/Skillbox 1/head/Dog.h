#pragma once

#include "Counting.h"
#include "Dancing.h"
#include "Swimming.h"

class Dog : protected Swimming, protected Dancing, protected Counting {
    std::vector<std::string> talents;
public:

    void addSwimming();

    void addDancing();

    void addCounting();

    void showTalents();

    Dog() {}

};

