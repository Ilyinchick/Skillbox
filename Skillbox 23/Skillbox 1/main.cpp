#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

int main() {
    int day;
    std::cout << "Enter day: " << std::endl;
    std::cin >> day;
    switch(day) {
        case 1: {
            std::cout << "Monday" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Tuesday" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Wednesday" << std::endl;
            break;
        }
        case 4: {
            std::cout << "Thursday" << std::endl;
            break;
        }
        case 5: {
            std::cout << "Friday" << std::endl;
            break;
        }
        case 6: {
            std::cout << "Saturday" << std::endl;
            break;
        }
        case 7: {
            std::cout << "Sunday" << std::endl;
            break;
        }
    }
    return 0;
}


