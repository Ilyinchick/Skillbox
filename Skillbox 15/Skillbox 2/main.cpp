#include <iostream>

int main() {

    int a[] = {2, 7, 11, 15};
    int result = 13;

    for (int i = 0; i < 4; i ++) {
        for (int j = i; j < 4; j++) {
            if (a[i] + a[j] == result) {
                std::cout << a[i] << " + " << a[j];
            }
        }
    }

    return 0;
}
