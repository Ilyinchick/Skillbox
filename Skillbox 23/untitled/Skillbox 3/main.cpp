#include <iostream>

#define SPRING "Spring"

int main() {
    int x = 2;
#if defined(WINTER)
    std::cout << WINTER;
#elif defined(SUMMER)
    std::cout << SUMEMR;
#elif defined(AUTUMN)
    std::cout << AUTUMN;
#elif defined(SPRING)
    std::cout << SPRING;
#endif
    return 0;
}
