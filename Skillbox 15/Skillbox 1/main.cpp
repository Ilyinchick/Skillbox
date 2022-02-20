#include <iostream>

int main() {
    int a[] = {-5, 60, 10, -50, -500, 80, 10, -5, 4};
    int summ = 0, left, right, maxSumm = a[0];

    for (int i = 0; i < 9; i++) {
        summ += a[i];

        if (summ < 0) {
            summ = 0;
            left = i + 1;
        }

        if (maxSumm < summ) {
            maxSumm = summ;
            right = i;
        }

    }
    std::cout << left << " - " << right;

    return 0;
}
