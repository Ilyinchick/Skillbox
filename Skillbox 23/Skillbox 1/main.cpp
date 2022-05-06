#include <iostream>

#define APPEND(word1, word2) word1 ##_## word2;
#define DAY_1 "Monday"
#define DAY_2 "Tuesday"
#define DAY_3 "Wednesday"
#define DAY_4 "Thursday"
#define DAY_5 "Friday"
#define DAY_6 "Saturday"
#define DAY_7 "Sunday"

void printDay(int i);

int main() {
    int i;
    std::cout << "Enter command: " << std::endl;
    std::cin >> i;
    if (i > 0 && i < 8) {
        switch (i) {
            case 1 :{
                std::cout << APPEND(DAY, 1)
                break;
            } case 2 :{
                std::cout << APPEND(DAY, 2)
                break;
            } case 3 :{
                std::cout << APPEND(DAY, 3)
                break;
            } case 4 :{
                std::cout << APPEND(DAY, 4)
                break;
            } case 5 :{
                std::cout << APPEND(DAY, 5)
                break;
            } case 6 :{
                std::cout << APPEND(DAY, 6)
                break;
            } case 7 :{
                std::cout << APPEND(DAY, 7)
                break;
            }
        }
    } else std::cout << "Wrong day number";

    return 0;
}



