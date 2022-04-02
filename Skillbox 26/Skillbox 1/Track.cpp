#include <ctime>
#include <string>
#include <iostream>


class Track {
    std::string name;
    std::tm date;
    int duration;
    bool isPaused;

public:

    void play() {
        if (isPaused) {
            isPaused = false;
            printInfo();
        }
    }

    void pause() {
        if (!isPaused) {
            isPaused = true;
            std::cout << "Paused" << std::endl;
        }
    }

    void printInfo() {
        std::cout << "Name: " << name << "\nDate: " << getDate() << "\nDuration: " << duration << std::endl;
    }

    std::string getDate() {
        return std::to_string(date.tm_hour) + ":" + std::to_string(date.tm_min) + " " + std::to_string(date.tm_mday)
        + "." + std::to_string(date.tm_mon + 1) + "." + std::to_string(date.tm_year + 1900);
    }

    std::string getName() {
        return name;
    }

    bool getStatus() {
        return isPaused;
    }

    void setStatus(bool status) {
        isPaused = status;
    }

    void setName(std::string newName) {
        name = newName;
    }

    void setDate(std::tm newDate) {
        date = newDate;
    }

    void setDuration(int i) {
        duration = i;
    }
};
