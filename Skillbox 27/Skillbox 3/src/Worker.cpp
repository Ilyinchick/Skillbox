#include "Worker.h"

void Worker::setIsWorking(bool b) {
    isWorking = b;
}

void Worker::setTask(char inTask) {
    task = inTask;
}

char Worker::getTask() {
    return task;
}

bool Worker::getIsWorking() {
    return isWorking;
}

void Worker::takeTask(int seed) {
    std::srand(seed + this->getId());
    setIsWorking(true);
    int task = std::rand() % 3;
    if (task == 0) setTask('A');
    else if (task == 1) setTask('B');
    else if (task == 2) setTask('C');
    else std::cout << "There is some error in Worker::takeTask() method." << std::endl;
    std::cout << getName() << " is took the " << getTask() << " task." << std::endl;
}
