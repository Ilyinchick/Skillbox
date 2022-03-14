#include <iostream>

#define FILL_ARR for(int i = 0; i < 10; i++) { std::cin >> arr[i];}
#define PRINT_ARR for(int i = 0; i < 10; i++) { std::cout << arr[i]<< " ";} std::cout << std::endl;
#define PRINT_CROWDED for(int i = 0; i < 10; i++) { if(arr[i] > 20) std::cout << "Wagon #" << i << " is crowded." << std::endl;}
#define FREE_PLACES for(int i = 0; i < 10; i++) { if(arr[i] < 20) std::cout << "In wagon #" << i << " is " << 20 - arr[i] << " empty place(s)." << std::endl;}

int main() {
    int arr[10];
    std::cout << "Fill wagons:" << std::endl;
    FILL_ARR
    PRINT_CROWDED
    FREE_PLACES
    return 0;
}
