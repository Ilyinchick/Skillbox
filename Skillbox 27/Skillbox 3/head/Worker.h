#pragma once

#include "Man.h"

class Worker : public Man {

    bool isWorking;
    char task;

public:
    Worker() {
        this->isWorking = false;
        this->task = '0';
        this->setName("Worker" + std::to_string(this->getId()));
    }

    void setIsWorking(bool b);

    void setTask(char task);

    char getTask();

    bool getIsWorking();

    void takeTask(int seed);
};
