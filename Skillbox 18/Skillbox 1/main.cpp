#include <iostream>
#include <vector>

void print (std::vector<int>& a, int arr[]);

void swapvec(std::vector <int>& a, int b[4]);

void swap (int* a, int* b);

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    int arr[4] = {2, 4, 6, 8};
    print(a, arr);
    swapvec(a, arr);
    std::cout << "After swap: " << std::endl;
    print(a, arr);
    return 0;
}

void print (std::vector<int>& a, int arr[]) {
    for (int i : a) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < a.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void swap (int* a, int* b) {
    int i = *a;
    *a = *b;
    *b = i;
}

void swapvec(std::vector <int>& a, int b[]) {
    for (int i = 0; i < a.size(); i++) {
        swap(&a[i], &b[i]);
    }
}