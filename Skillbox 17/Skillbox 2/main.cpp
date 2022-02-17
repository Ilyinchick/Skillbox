#include <iostream>

void reverse (int* arr);

void swap (int* a, int* b);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    reverse(arr);

    for (int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}

void reverse (int* arr) {
    for (int i = 0; i < 5; i++) {
        swap((arr+i), (arr + 9 - i));
    }
}

void swap (int* a, int* b) {
    int x = *a;
    *a = *b;
    *b = x;
}
