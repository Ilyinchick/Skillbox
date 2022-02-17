#include <iostream>

void enter(int arr[4][4]);

void print(int arr[4][4]);

void diagonal(int arr[4][4]);

int main() {
    int M[4][4];
    std::cout << "Enter matrix" << std::endl;
    enter(M);
    print(M);
    diagonal(M);
    std::cout << "Matrix after change" << std::endl;
    print(M);
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

void diagonal(int arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) arr[i][j] = 0;
        }
    }
}