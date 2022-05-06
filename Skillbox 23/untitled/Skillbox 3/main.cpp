#include <iostream>

#define SPRING "Spring"

int main() {
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
