#include <iostream>

void enter(int arr[4][4]);

void print(int arr[4][4]);

bool isEqual(int A[4][4], int B[4][4]);

int main() {
    int A[4][4], B[4][4];
    std::cout << "Enter A" << std::endl;
    enter(A);
    print(A);
    std::cout << "Enter B" << std::endl;
    enter(B);
    print(B);
    if (isEqual(A, B)) std::cout << "Equal";
    else std::cout << "Not equal";
    return 0;
}

void enter(int arr[4][4]) {
    int x;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> x;
            arr[i][j] = x;
        }
    }
}

void print(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isEqual(int A[4][4], int B[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}
