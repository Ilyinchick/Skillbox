#include <iostream>

template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8): ";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

template < typename T >
T calc(T array[8]) {
    T middle = 0;
    for (int i = 0; i < 8; i++) {
        middle += array[i];
    }
    middle /= 8;
    return middle;
}



int main() {
    double arr[8];
    input(arr);
    std::cout << calc(arr) << std::endl;

    int arr2[8];
    input(arr2);
    std::cout << calc(arr2) << std::endl;

    float arr3[8];
    input(arr3);
    std::cout << calc(arr3) << std::endl;

    return 0;
}
