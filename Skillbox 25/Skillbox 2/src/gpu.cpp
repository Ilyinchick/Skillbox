#include "gpu.h"

void display(int* arr) {
    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}
