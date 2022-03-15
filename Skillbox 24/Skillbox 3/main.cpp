#include <iostream>
#include <ctime>

std::tm enterTime();

void encrementSec(std::tm* dummy);

void decrementSec(std::tm* timer);

int main() {
    std::tm timer = enterTime();

    std::time_t dummy = std::time(nullptr);
    std::tm secWait = *std::localtime(&dummy);
    encrementSec(&secWait);

    while(true) {
        std::time_t t = std::time(nullptr);
        std::tm local = *std::localtime(&t);
        if (local.tm_sec == secWait.tm_sec) {
            decrementSec(&timer);
            std::cout << timer.tm_min << ":" << timer.tm_sec << std::endl;
            encrementSec(&secWait);
        }
        if (timer.tm_min == 0 && timer.tm_sec == 0) break;
    }
    std::cout << "Ding! Ding! Ding!" << std::endl;
    return 0;
}

std::tm enterTime() {
    int min, sec;
    std::tm timer;
    std::cout << "Enter minutes for timer:" << std::endl;
    std::cin >> min;
    std::cout << "Enter seconds for timer:" << std::endl;
    std::cin >> sec;
    timer.tm_min = min;
    timer.tm_sec = sec;
    return timer;
}

void encrementSec(std::tm* dummy) {
    if (dummy->tm_sec == 59) {
        dummy->tm_min++;
        dummy->tm_sec = 0;
    } else dummy->tm_sec++;
}

void decrementSec(std::tm* timer) {
    if (timer->tm_sec == 0 && timer->tm_min != 0) {
        timer->tm_min--;
        timer->tm_sec = 59;
    } else timer->tm_sec--;
}