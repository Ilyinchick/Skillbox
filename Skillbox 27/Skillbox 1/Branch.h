#pragma once

#include <vector>
#include <ctime>
#include <string>
#include <iostream>

class Branch {
    Branch *parent;
    std::vector<Branch*> children;
    std::string habitat;

public:
    Branch() {
        this->parent = nullptr;
        this->habitat = "";
        for (int i = 0; i < std::rand() % 3 + 3; i++) {
        children.push_back(new Branch(this));
        }
    }

    Branch(Branch *parent) {
        this->parent = parent;
        if (this->parent->parent == nullptr) {
            for (int i = 0; i < rand() % 1 + 2; i ++) {
                this->children.push_back(new Branch(this));
            }
        }
    }

    void setName();

    void fillTree();

    int countOfNeighbors();

    Branch* searchBranch(std::string name);

    void setHabitat(std::string name);

    std::string getHabitat() {
        return this->habitat;
    }


};
