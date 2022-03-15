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
    *mounth = 12;
    *day = 31;
    for (birthday b: birthList) {
        if (b.birth.tm_mon >= now.tm_mon) {
            if (b.birth.tm_mon - now.tm_mon <= *mounth) {
                *mounth = b.birth.tm_mon;
                if (b.birth.tm_mday <= *day) *day = b.birth.tm_mday;
            }
        }
    }
}
