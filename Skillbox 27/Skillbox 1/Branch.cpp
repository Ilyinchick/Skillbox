#include "Branch.h"
#include "assert.h"


void Branch::fillTree() {
    assert(this->parent == nullptr);
        for (Branch* b: children) {
            b->setName();
            for (Branch* c: b->children) {
                c->setName();
            }
        }
}

void Branch::setHabitat(std::string name) {
    if (name != "None") this->habitat = name;
}

int Branch::countOfNeighbors() {
    int count = 0;
    if (this->parent->parent == nullptr) {
        for (Branch* b: this->children) {
            if (b->getHabitat() != "") {
                count++;
            }
        }
    } else {
        if (parent->getHabitat() != "") count++;
        for (Branch* b: parent->children) {
            if (b->getHabitat() != "") count++;
        }
        count--;        //subtract habitat itself
    }
    return count;
}

Branch* Branch::searchBranch(std::string name) {
    assert(this->parent == nullptr);
    Branch* tree = new Branch();
    tree->habitat = "NoMatch";
    for (Branch* b: children) {
        if (b->habitat == name)  return b;
        for (Branch* c: b->children) {
            if (c->habitat == name)  return c;
        }
    }
    return tree;
}

void Branch::setName() {
    std::string name;
    std::cout << "Enter name for a habitat: " << std::endl;
    std::cin >> name;
    if (name != "None" || name != "none") this->setHabitat(name);
}


