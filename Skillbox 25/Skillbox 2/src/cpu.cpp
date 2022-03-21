#include "cpu.h"


void compute(int arr[8]) {
    int summ = 0;
    for (int i = 0; i < 8; i++) {
        summ += arr[i];
    }
    std::cout << summ << std::endl;
}