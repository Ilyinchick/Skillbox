#include <iostream>

int main() {
    int a[] = {-5, 300, 900, -50, -2000, 800, 800, -5, 4};
    int summ = a[0], left = 0, right = 0, maxSumm = a[0], bestLeft, bestRight;

    for (int i = 1; i < 9; i++) {

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
