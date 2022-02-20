#include <iostream>

int main() {
    int a[] = {-5, 60, 10, -50, -500, 80, 10, -5, 4};
    int summ, left, right, maxSumm = a[0];

    for (int i = 0; i < 9; i++) {
        summ = 0;

        for (int j = i + 1; j < 9; j++) {
            summ += a[j];
            if (maxSumm < summ){
                maxSumm = summ;
                right = j;
                left = i + 1;
            }
        }

    }
    std::cout << left << " - " << right;

    return 0;
}
