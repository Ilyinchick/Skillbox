#include "Director.h"
#include "Manager.h"
#include "Worker.h"
#include <ctime>

int Man::countEntities = 0;

int main() {
    bool flag = true;
    int command;
    std::srand(std::time(nullptr));
    Director *director = new Director();

    std::cout << "Enter count of teams: " << std::endl;
    std::cin >> command;
    director->generateManagers(command);

    std::cout << "Enter count of workers in each team: " << std::endl;
    std::cin >> command;
    for (Manager *m: director->getManagers()) {
        m->generateTeam(command);
    }

    while (flag) {
        flag = false;
        std::cout << "Enter your command: " << std::endl;
        std::cin >> command;
        for (Manager* m: director->getManagers()) {
            m->generateTasks(command);
        }
        for (Manager* m: director-> getManagers()) {
            for (Worker* w: m->getTeam()) {
                if (!w->getIsWorking()) flag = true;
            }
        }
    }

    director = nullptr;
    delete director;

    return 0;
}
