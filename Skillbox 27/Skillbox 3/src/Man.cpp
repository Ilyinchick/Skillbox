#include "Man.h"

void Man::setName(std::string inName) {
    this->name = inName;
}

std::string Man::getName() {
    return this->name;
}

void Man::setId(int inId) {
    this->id = inId;
}

int Man::getId() {
    return this->id;
}

void Man::print() {
    std::cout << this->getId() << ". " << this->getName() << std::endl;
}

void Man::increase() {
    Man::countEntities += 1;
}

void Man::setCount(int count) {
    Man::countEntities = count;
}

int Man::getCount() {
    return Man::countEntities;
}
