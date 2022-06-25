#pragma once

#include <iostream>

class Swimmer {
    std::string name;
    int speed;
    int totalTime;

public:
    Swimmer(std::string inName, int inSpeed) {
        this->name = inName;
        this->speed = inSpeed;
    }

    std::string getName();

    int getSpeed();

    void setTotalTime(int time);

    int getTotalTime();
};
