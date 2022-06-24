#include <cassert>
#include "Manager.h"

void Manager::generateTeam(int count) {
    for (int i = 0; i < count; i++) {
        this->team.push_back(new Worker());
    }
}

void Manager::generateTasks(int seed) {
    std::cout << this->getName() << " is took command " << seed << std::endl;
        for (int i = 0; i < seed + this->getId(); i++) {
            if (i < this->getTeam().size()) this->team[i]->takeTask(seed);
        }

}

std::vector<Worker *> Manager::getTeam() {
    return this->team;
}
