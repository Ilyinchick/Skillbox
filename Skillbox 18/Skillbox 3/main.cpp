#include <iostream>

int jump(int n, int height);

int main() {
    std::cout << jump(6, 4);
    return 0;
}

int jump(int n, int height) {
    int result = 0, k = 0;
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;

    while (k < height) {
        k++;
        result += jump(n - k, height);
    }
    return result;
}
