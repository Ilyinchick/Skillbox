#include <iostream>

void fillArr(int arr[5][5][11]);

void printArr(int arr[5][5][11]);

int main() {
    int arr[5][5][11];

    fillArr(arr);
    printArr(arr);

    return 0;
}

void fillArr(int arr[5][5][11]) {
    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j++) {
            int x;
            std::cout << "Enter the post height in coordinate " << i << " - " << j << std::endl;
            std::cin >> x;
            for(int t = 0; t < x; t++) {
                arr[i][j][t] = 1;
            }
        }
    }
}

void printArr(int arr[5][5][11]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int count = 0;
            for (int t = 0; t < 11; t++){
                if (arr[i][j][t] == 1) count++;
            }
            std::cout << count;
        }
        std::cout << std::endl;
    }
}
