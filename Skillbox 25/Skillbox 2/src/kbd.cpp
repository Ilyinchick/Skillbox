#include "kbd.h"

void input(int arr[8]) {
    std::cout << "Enter 8 values for ram: " << std::endl;
    for(int i = 0; i < 8; i++) {
        arr[i] = enterInt();
    }
}