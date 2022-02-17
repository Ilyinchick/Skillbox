#include <iostream>

int main() {
    int arr [5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = (i * 5 + j) + i%2 * (-2 * j + 4);
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
