#pragma once

#include "Man.h"
#include "Manager.h"

class Director:public Man {
    std::vector<Manager*> managers;


public:

    Director() {
        this->setName("Director");
    }

    void generateManagers(int count);

    std::vector<Manager*> getManagers();
};
