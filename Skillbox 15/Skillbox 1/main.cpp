#include <iostream>

int main() {
    int a[] = {-5, 10, 500, -50, -1000, 400, 600, -5, 4};
    int summ = a[0], left = 0, right = 0, maxSumm = a[0];

    for (int i = 1; i < 9; i++) {

        summ += a[i];
        if (summ > maxSumm) {
            maxSumm = summ;
            right = i;
        }
        if (a[i] > summ) {
            summ = a[i];
            left = i;
        }

    }
    std::cout << left << " - " << right << "    " << maxSumm;

    return 0;
}
