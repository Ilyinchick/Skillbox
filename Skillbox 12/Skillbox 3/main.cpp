#include <iostream>

int partition (float arr[], int low, int high);

void print(float arr[]);

void quickSort(float arr[], int low, int high);

void swap (float arr[], int a, int b);

int main() {
    float numbers [15] = {1, 2,3,4,5,6,7,2,3,4,10,12,13,8,9};

    for (float f : numbers) {
        std::cout << f << " ";
    }
    std::cout << "\n";
    quickSort(numbers, 0, 14);
    print(numbers);

    return 0;
}

int partition (float arr[], int low, int high) {
    int pivotIndex = high;

    for (int j = 0; j < high; j++)
    {
        if (arr[j] > arr[pivotIndex]) {
            swap(arr, j, pivotIndex);
        }
    }
    return pivotIndex;
}

void quickSort(float arr[], int low, int high) {
    int pivot = partition(arr, low, high);
    if (low < high)
    {
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void print(float arr[]) {
    std::cout << "\n";
    for (int i = 0; i < 15; i++) {
        std::cout << arr[i] << " ";
    }
}

void swap (float arr[], int a, int b) {
    int i = arr[a];
    arr[a] = arr[b];
    arr[b] = i;
}
