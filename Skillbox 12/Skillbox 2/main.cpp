#include <iostream>

int main() {
    int number[15] = {114,111, 106, 109, 108, 105, 115,  116, 110, 109, 107, 113, 119, 117, 118};
    int summ = 0, min = number[0], avg;

    for (int i : number) {
        summ += i;
        if (i < min) min = i;
    }
    avg = min + 7;
    std::cout << avg + ((summ - min * 15) - min);
    return 0;
}
