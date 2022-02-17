#include <iostream>

void swap(int* a, int* b);

int main() {
    int a = 10, b = 20;
    std::cout << a << " " << b << std::endl;
    swap(&a, &b);
    std::cout << a << " " << b;
    return 0;
}

void swap(int* a, int* b) {
    int x = *a;
    *a = *b;
    *b = x;
}
