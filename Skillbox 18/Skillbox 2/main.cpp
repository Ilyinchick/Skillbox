#include <iostream>

int jump(int n);

int main() {
    std::cout << jump(4);
    return 0;
}

int jump(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    return jump(n-1) + jump(n-2) + jump(n-3);
}
