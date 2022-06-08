#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>


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

    void setName() {
        std::cout << "Enter track name: " << std::endl;
        std::cin >> name;
    }

    void setDate() {
        std::time_t t = std::time(nullptr);
        std::tm local = *std::localtime(&t);
        std::cout << "Enter date of track (year/month/day):" << std::endl;
        std::cin >> std::get_time(&local, "%Y/%m/%d");
        date = local;
    }

    void setDuration() {
        std::cout << "Enter duration of track: " << std::endl;
        std::cin >> duration;
    }

    void initializeTrack() {
        setName();
        setDuration();
        setDate();
        isPaused = true;
    }
};
