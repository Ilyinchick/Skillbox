#include "Track.h"

void Track::play() {
    if (isPaused) {
        isPaused = false;
        printInfo();
    }
}

void Track::pause() {
    if (!isPaused) {
        isPaused = true;
        std::cout << "Paused" << std::endl;
    }
}

void Track::printInfo() {
    std::cout << "Name: " << name << "\nDate: " << getDate() << "\nDuration: " << duration << std::endl;
}

std::string Track::getDate() {
    return std::to_string(date.tm_hour) + ":" + std::to_string(date.tm_min) + " " + std::to_string(date.tm_mday)
           + "." + std::to_string(date.tm_mon + 1) + "." + std::to_string(date.tm_year + 1900);
}

bool Track::getStatus() {
    return isPaused;
}

void Track::setStatus(bool status) {
    isPaused = status;
}

void Track::setName() {
    std::cout << "Enter track name: " << std::endl;
    std::cin >> name;
}

void Track::setDate() {
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    std::cout << "Enter date of track (year/month/day):" << std::endl;
    std::cin >> std::get_time(&local, "%Y/%m/%d");
    date = local;
}

void Track::setDuration() {
    std::cout << "Enter duration of track: " << std::endl;
    std::cin >> duration;
}

void Track::initializeTrack() {
    setName();
    setDuration();
    setDate();
    isPaused = true;
}
