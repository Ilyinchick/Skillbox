#include "Man.h"

void Man::setName(std::string inName) {
    name = inName;
}

std::string Man::getName() {
    return name;
}

void Man::setId(int inId) {
    id = inId;
}

int Man::getId() {
    return id;
}

void Man::print() {
    std::cout << getId() << ". " << getName() << std::endl;
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
