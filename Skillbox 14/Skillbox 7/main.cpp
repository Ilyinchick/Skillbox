#include <iostream>

void fillArr(bool arr[12][12]);

void printArr(bool arr[12][12]);

void popArr(bool arr[12][12], int x1, int y1, int x2, int y2);

bool correctCoordinates(int x1, int y1, int x2, int y2);

bool isArrEmpty(bool arr[12][12]);

int main() {
    bool arr[12][12];
    int x1, y1, x2, y2;

    fillArr(arr);

    do {
        printArr(arr);
        std::cout << "Enter start coordinates: ";
        std::cin >> x1 >> y1;
        std::cout << "Enter finish coordinates: ";
        std::cin >> x2 >> y2;
        popArr(arr, x1, y1, x2, y2);
    } while (!isArrEmpty(arr));

    std::cout << "Well done!";

    return 0;
}

void fillArr(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            arr[i][j] = true;
        }
    }
}

void printArr(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j]) std::cout << "o ";
            else std::cout << "x ";
        }
        std::cout << std::endl;
    }
}

void popArr(bool arr[12][12], int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            if (arr[i][j]) {
                arr[i][j] = false;
                std::cout << "Pop!" << std::endl;
            }
        }
    }
}

bool correctCoordinates(int x1, int y1, int x2, int y2) {
    if (x1 >= 0 && x1 < 12 && x2 >= 0 && x2 < 12 && y1 >= 0 && y1 < 12 && y2 >= 0 && y2 < 12) return true;
    else return false;
}

bool isArrEmpty(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j]) return false;
        }
    }
    return true;
}