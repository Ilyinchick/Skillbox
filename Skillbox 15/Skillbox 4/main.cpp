#include <iostream>

int partition (int arr[], int low, int high);

void print(int arr[]);

void quickSort(int arr[], int low, int high);

void swap (int arr[], int a, int b);

int main() {
    int arr[] = {-100,-50, -5, 1, 10, 15};

    quickSort(arr, 0, 5);
    print(arr);

    return 0;
}

int partition (int arr[], int low, int high) {
    int pivotIndex = high;

    for (int j = 0; j < high; j++)
    {
        if (std::abs(arr[j]) > std::abs(arr[pivotIndex])) {
            swap(arr, j, pivotIndex);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int low, int high) {
    int pivot = partition(arr, low, high);
    if (low < high)
    {
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void print(int arr[]) {
    std::cout << "\n";
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
}

void swap (int arr[], int a, int b) {
    int i = arr[a];
    arr[a] = arr[b];
    arr[b] = i;
}
