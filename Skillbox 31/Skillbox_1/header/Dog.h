#pragma once

#include "Shared_ptr_toy.h"

class Dog {
private:
    std::string name;
    int age;
    Shared_ptr_toy lovely_toy;

public:

    Dog() {}

    Dog(std::string _name, int _age, Shared_ptr_toy* ptr) {
        name = _name;
        if (_age >= 0 && _age <= 30) age = _age;
        else age = 0;
        lovely_toy = *ptr;
    }
};


