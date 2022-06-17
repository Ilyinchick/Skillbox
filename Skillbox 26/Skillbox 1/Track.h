#pragma once

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

    void play();

    void pause();

    void printInfo();

    std::string getDate();

    bool getStatus();

    void setStatus(bool status);

    void setName();

    void setDate();

    void setDuration();

    void initializeTrack();
};