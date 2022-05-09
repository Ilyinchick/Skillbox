#include <iostream>
#include <ctime>
#include <vector>

struct task {
    std::string name;
    int time;
};

std::vector<task> taskVector;

void printTasks(std::vector<task>* vec);

int main() {
    std::string input, taskName;
    bool tsk = false;
    int time;

    while (true) {
        std::cin >> input;
        if (input == "exit") break;
        else {
            if (input == "begin") {
                if (tsk) {
                    task task;
                    time = std::time(nullptr) - time;
                    task.name = taskName;
                    task.time = time;
                    taskVector.push_back(task);
                }
                tsk = true;
                std::cout << "Enter task name:" << std::endl;
                std::cin >> taskName;
                time = std::time(nullptr);
            } else if (input == "end") {
                if (tsk) {
                    tsk = false;
                    time = std::time(nullptr) - time;
                    task task;
                    task.name = taskName;
                    task.time = time;
                    taskVector.push_back(task);
                } else {
                    std::cout << "There is no task right now." << std::endl;
                }
            } else if (input == "status") {
                printTasks(&taskVector);
                if (tsk) std::cout << taskName << std::endl;
            } else {
                std::cout << "Invalid input." << std::endl;
            }
        }
    }

    return 0;
}

void printTasks(std::vector<task>* vec) {
    for (task t: *vec) {
        std::cout << t.name << ": " << t.time << std::endl;
    }
}
