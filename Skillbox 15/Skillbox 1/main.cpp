#include <iostream>

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int summ = a[0], left = 0, right = 0, maxSumm = a[0], bestLeft;

    for (int i = 1; i < 9; i++) {

        if (summ > 0 && a[i] < 0 && std::abs(a[i]) > summ) {
            summ = a[i];
        }

        summ += a[i];

        if (a[i] > summ) {
            summ = a[i];
            if (i > right)  bestLeft = i;
            else left = i;
        }
        if (summ > maxSumm) {
            maxSumm = summ;
            right = i;
        }
        if (bestLeft < right)   left = bestLeft;
        if (maxSumm < maxSumm - a[left]) {
            maxSumm = maxSumm - a[left];
            left++;
        }

    }
    std::cout << left << " - " << right << "    " << maxSumm;

    return 0;
}
