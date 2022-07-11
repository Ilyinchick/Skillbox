#include <iostream>

#include "Dog.h"


int main() {
    Shared_ptr_toy* ball = new Shared_ptr_toy("Ball");

    Dog* d1 = new Dog("D1", 15, ball);

    return 0;
}
