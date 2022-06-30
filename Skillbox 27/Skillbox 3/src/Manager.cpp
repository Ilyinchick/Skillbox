#include <cassert>
#include "Manager.h"

void Manager::generateTeam(int count) {
    for (int i = 0; i < count; i++) {
        team.push_back(new Worker());
    }
}

void Manager::generateTasks(int seed) {
    std::cout << getName() << " is took command " << seed << std::endl;
        for (int i = 0; i < seed + getId(); i++) {
            if (i < this->getTeam().size()) team[i]->takeTask(seed);
        }

}

std::vector<Worker *> Manager::getTeam() {
    return team;
}
