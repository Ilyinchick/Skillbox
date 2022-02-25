#include <iostream>

void evendigits(long long number, int* ans);

int main() {
    int ans = 0;
    long long number = 9223372036854775800;
    evendigits(number, &ans);
    std::cout << ans;
    return 0;
}

void evendigits(long long number, int* ans) {
    if (number > 0) {
        evendigits(number / 10, ans);
    }
    if (number % 2 == 0 && number > 0) *ans += 1;
}
