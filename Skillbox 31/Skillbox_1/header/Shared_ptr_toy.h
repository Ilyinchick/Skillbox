#pragma once

#include "Toy.h"

class Shared_ptr_toy {

private:
    Toy *ptr_toy;
    //int refs;

public:

    Shared_ptr_toy() {}

    Shared_ptr_toy(std::string name) : ptr_toy(new Toy(name)) {}

    Shared_ptr_toy(const Shared_ptr_toy &oth) : ptr_toy(oth.ptr_toy) {}

    Shared_ptr_toy &operator=(const Shared_ptr_toy &oth) {
        if (this == &oth) return *this;
        if (ptr_toy != nullptr) {
            delete ptr_toy;
        }
        ptr_toy = new Toy(oth.ptr_toy);
        return *this;
    }

    ~Shared_ptr_toy() {
        delete ptr_toy;
    }
};
