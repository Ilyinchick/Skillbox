#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

struct birthday {
    std::string name;
    std::tm birth;
};

std::vector<birthday> birthList;

void addRecord(std::string name);

void printMathes(int mounth, int day);

void findClosestDate(int *mounth, int *day);

int main() {
    std::string input;
    int mounth, day;
    while (true) {
        std::cout << "Enter name:" << std::endl;
        std::cin >> input;
        if (input == "end") break;
        else {
            addRecord(input);
        }
    }
    findClosestDate(&mounth, &day);
    printMathes(mounth, day);
    return 0;
}

void addRecord(std::string name) {
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    birthday bigDay;
    std::string date;

    bigDay.name = name;
    std::cout << "Enter birthday:" << std::endl;
    std::cin >> std::get_time(&local, "%Y/%m/%d");
    bigDay.birth = local;
    birthList.push_back(bigDay);
}

void printMathes(int mounth, int day) {
    for (birthday b: birthList) {
        if (b.birth.tm_mon == mounth && b.birth.tm_mday == day)
            std::cout << b.name << " - " << b.birth.tm_mon + 1 << "/" << b.birth.tm_mday << std::endl;
    }
}

void findClosestDate(int *mounth, int *day) {
    std::time_t t = std::time(nullptr);
    std::tm now = *std::localtime(&t);
    *mounth = 13;
    *day = 32;

    for (birthday b: birthList) {

        if (b.birth.tm_mon < now.tm_mon) {
            if ( (12 - now.tm_mon + b.birth.tm_mon) < *mounth) {
                *mounth = b.birth.tm_mon;
                *day = b.birth.tm_mday;
            } else if ((12 - now.tm_mon + b.birth.tm_mon) == *mounth) {
                if (now.tm_mday <= b.birth.tm_mday) {
                    *mounth = b.birth.tm_mon;
                    *day = b.birth.tm_mday;
                }
            }

        } else if (b.birth.tm_mon > now.tm_mon) {
            if (b.birth.tm_mon - now.tm_mon < *mounth) {
                *mounth = b.birth.tm_mon;
                *day = b.birth.tm_mday;
            } else if (b.birth.tm_mon - now.tm_mon == *mounth) {
                if (now.tm_mday <= b.birth.tm_mday) {
                    *mounth = b.birth.tm_mon;
                    *day = b.birth.tm_mday;
                }
            }

        } else {
            if (now.tm_mday <= b.birth.tm_mday) {
                if ((12 - now.tm_mon + b.birth.tm_mon) < *mounth) {
                    *mounth = b.birth.tm_mon;
                    *day = b.birth.tm_mday;
                } else if ((12 - now.tm_mon + b.birth.tm_mon) == *mounth) {
                    if (now.tm_mday <= b.birth.tm_mday) {
                        *mounth = b.birth.tm_mon;
                        *day = b.birth.tm_mday;
                    }
                }
            }
        }
    }
}
