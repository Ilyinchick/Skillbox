#include "Worker.h"

void Worker::setIsWorking(bool b) {
    this->isWorking = b;
}

void Worker::setTask(char inTask) {
    this->task = inTask;
}

char Worker::getTask() {
    return this->task;
}

bool Worker::getIsWorking() {
    return this->isWorking;
}

void Worker::takeTask(int seed) {
    std::srand(seed + this->getId());
    this->setIsWorking(true);
    int task = std::rand() % 3;
    if (task == 0) this->setTask('A');
    else if (task == 1) this->setTask('B');
    else if (task == 2) this->setTask('C');
    else std::cout << "There is some error in Worker::takeTask() method." << std::endl;
    std::cout << this->getName() << " is took the " << this->getTask() << " task." << std::endl;
}
