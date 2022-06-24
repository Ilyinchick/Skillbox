#include "Director.h"

void Director::generateManagers(int count) {
    for (int i = 0; i < count; i++) {
        this->managers.push_back(new Manager());
    }
}

std::vector<Manager *> Director::getManagers() {
    return this->managers;
}


