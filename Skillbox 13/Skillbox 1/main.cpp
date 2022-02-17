#include <iostream>
#include <vector>

std::vector <int> remove(std::vector <int> vec, int n);

int main() {
    int n, k;
    std::vector <int> vec;

    std::cout << "Enter first digit: " << std::endl;
    std::cin >> k;
    std::cout << "Enter digits: " << std::endl;

    for (int i = 0; i < k; i++) {
        std::cin >> n;
        vec.push_back(n);
    }
    std::cout << "Enter digit to remove" << std::endl;
    std::cin >> n;

    vec = remove(vec, n);
    for (int i : vec) std::cout << i << " ";

    return 0;
}

std::vector <int> remove(std::vector <int> vec, int n) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == n) {
            for (int j = i; j < vec.size(); j++) {
                if (j == vec.size()) vec.pop_back();
                else vec[j] = vec[j+1];
            }
            i--;
            vec.pop_back();
        }
    }
    return vec;
}
