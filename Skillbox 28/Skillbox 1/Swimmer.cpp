#include "Swimmer.h"

int Swimmer::getSpeed() {
    return this->speed;
}

std::string Swimmer::getName() {
    return this->name;
}

void Swimmer::setTotalTime(int time) {
    this->totalTime = time;
}

int Swimmer::getTotalTime() {
    return this->totalTime;
}
