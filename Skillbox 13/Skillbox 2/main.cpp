#include <iostream>
#include <vector>


int main() {
    std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
    std::vector<int> basket = {1, 1, 3, 3};
    float totalPrice = 0;
    for (int i : basket) {
        totalPrice += price[i];
    }
    std::cout << totalPrice << std::endl;
    return 0;
}
