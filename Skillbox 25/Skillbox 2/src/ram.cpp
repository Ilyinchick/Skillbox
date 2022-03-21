#include "ram.h"

void write() {
    std::cout << "Enter 8 values for ram: " << std::endl;
    for(int i = 0; i < 8; i++) {
        ram[i] = enterInt();
    }
}

void read() {
    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << ram[i] << " ";
    }
    std::cout << std::endl;
}