#include <iostream>

int partition (int arr[], int low, int high);

void print(int arr[]);

void quickSort(int arr[], int low, int high);

void swap (int arr[], int a, int b);

void add(int arr[], int number);

int size, capacity;


int main() {
    size = 0, capacity = 10;
    int numbers [capacity];
    int number;

    std::cout << "Enter array: " << std::endl;
    do {
        std::cin >> number;
        if (number != -1) {
            add(numbers, number);
        } else {
            quickSort(numbers, 0, size);
            std::cout << numbers[4] << std::endl;
        }
    } while (number != -2);
    quickSort(numbers, 0, 14);
    print(numbers);

    return 0;
}

void add(int arr[], int number) {
    if (capacity - size == 1) {
        int newCapacity = capacity * 2;
        int newArr[newCapacity];
        for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
        capacity = newCapacity;
        }
        arr = newArr;
    }
    arr[size+1] = number;
    size++;

}

int partition (int arr[], int low, int high) {
    int pivotIndex = high;

    for (int j = 0; j < high; j++)
    {
        if (arr[j] > arr[pivotIndex]) {
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
    for (int i = 0; i < 15; i++) {
        std::cout << arr[i] << " ";
    }
}

void swap (int arr[], int a, int b) {
    int i = arr[a];
    arr[a] = arr[b];
    arr[b] = i;
}
