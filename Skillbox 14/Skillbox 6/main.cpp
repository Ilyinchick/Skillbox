#include <iostream>

void enter(float arr[4][4]);

void print(float arr[4][4]);

void enterVec(float arr[4]);

void printVec(float arr[4]);

void multiply(float arr[4][4], float V[4], float R[4]);

int main() {
    float M[4][4], V[4], R[4] = {0, 0, 0, 0};
    std::cout << "Enter matrix" << std::endl;
    enter(M);
    print(M);
    std::cout << "Enter vector" << std::endl;
    enterVec(V);
    printVec(V);
    multiply(M, V, R);
    std::cout << "Matrix after change" << std::endl;
    printVec(R);
    return 0;
}

void enter(float arr[4][4]) {
    int x;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> x;
            arr[i][j] = x;
        }
    }
}

void print(float arr[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void enterVec(float arr[4]) {
    float x;
    for(int i = 0; i < 4; i++) {
        std::cin >> x;
        arr[i] = x;
    }
}

void printVec(float arr[4]) {
    for(int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void multiply(float arr[4][4], float V[4], float R[4]) {
    for(int i = 0; i < 4; i++) {
        float summ = 0;
        for (int j = 0; j < 4; j++) {
            summ = arr[i][j] * V[j];
            R[i] += summ;
        }
    }
}