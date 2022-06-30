#include "Branch.h"


void Branch::fillTree() {
    if (parent != nullptr) setName();
    if (!children.empty()) {
        for (Branch *b: children) {
            b->fillTree();
        }
    }
}

void Branch::setHabitat(std::string name) {
    if (name != "None") this->habitat = name;
}

void Branch::countOfNeighbors(int *count) {
    if (getHabitat() != "") *count += 1;
    if (!children.empty()) {
        for (Branch* b: children) {
            b->countOfNeighbors(count);
        }
    }
}

Branch *Branch::searchBranch(std::string name) {
    if (getHabitat() != name) {
        for (Branch* b: children) {
            if (b->searchBranch(name) != nullptr) return b->searchBranch(name);
        }
    } else return this;
    return nullptr;
}


void Branch::setName() {
    std::string name;
    std::cout << "Enter name for a habitat: " << std::endl;
    std::cin >> name;
    if (name != "None" || name != "none") this->setHabitat(name);
}

Branch *Branch::searchBigBranch() {
    if (parent->parent == nullptr) return this;
    else parent->searchBigBranch();
}


