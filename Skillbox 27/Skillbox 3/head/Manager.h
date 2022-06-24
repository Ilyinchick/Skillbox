#pragma once

#include "Man.h"
#include "Worker.h"

class Manager: public Man {
    std::vector<Worker*> team;

public:

    Manager() {
        this->setName("Manager" + std::to_string(this->getId()));
    }

    void generateTeam(int count);

    void generateTasks(int seed);

    std::vector<Worker*> getTeam();

};



