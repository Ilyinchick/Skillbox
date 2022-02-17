#include <iostream>

int main() {
    int a[] = {10,1,-3,4,-1,2,1,-5,4};
    int max = a[0], summ, left, right;

    for (int i = 0; i < 9; i++) {
        for (int j = 8; j >= 0; j--) {
            summ = a[0];
            for(int n = i; n <= j; n++){
                summ += a[n];
            }
            if (max < summ) {
                max = summ;
                left = i;
                right = j;
            }
        }
    }
    std::cout << left << " - " << right;

    return 0;
}
