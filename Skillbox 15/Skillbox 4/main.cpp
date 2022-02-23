#include <iostream>

void print(int arr[], int size, int min);

int findMinAbs(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {-100, -50, -5, 1, 10, 15};

    print(arr, 5, findMinAbs(arr, 5));

    return 0;
}

void print(int arr[], int size, int min) {
    int left, right;
    bool leftF = false, rightF = false;

    if (min == 0) {
        left = min;
        right = min + 1;
    } else if (min == size) {
        right = min;
        left = min - 1;
    } else {
        left = min;
        right = min + 1;
    }

    while (!leftF || !rightF) {
        if (rightF) {
            if (!leftF && left == 0) {
                std::cout << arr[left] << " ";
                leftF = true;
            } else {
                std::cout << arr[left] << " ";
                left--;
            }
            continue;
        } else if (leftF) {
            if (right == size && !rightF) {
                std::cout << arr[right] << " ";
                rightF = true;
            } else {
                std::cout << arr[right] << " ";
                right++;
            }
            continue;
        }

        if (std::abs(arr[left]) < std::abs(arr[right])) {
            if (left == 0 && !leftF) {
                std::cout << arr[left] << " ";
                left = true;
            } else {
                std::cout << arr[left] << " ";
                left--;
            }
        } else {
            if (right == size && !rightF) {
                std::cout << arr[right] << " ";
                rightF = true;
            } else {
                std::cout << arr[right] << " ";
                right++;
            }
        }
    }
}

int findMinAbs(int arr[], int size) {
    int min = 0;
    for (int i = 1; i < size; i++) {
        if (std::abs(arr[min]) > std::abs(arr[i])) min = i;
    }
    return min;
}