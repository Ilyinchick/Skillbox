#include "Branch.h"

int main() {
    std::srand(std::time(nullptr));
    std::vector<Branch*>trees;
    std::string name;

    for (int i = 0; i < 5; i++) {
        Branch* tree = new Branch();
        trees.push_back(tree);
   }

    for (Branch* b: trees) {
        b->fillTree();
    }

    std::cout << "Enter a habitat's name: " << std::endl;
    std::cin >> name;

    for (Branch* b: trees) {
        if (b->searchBranch(name)->getHabitat() != "NoMatch") {
            std::cout << name << " has " << b->searchBranch(name)->countOfNeighbors() << " neighbors." << std::endl;
        } else {
            std::cout << "There is no such habitat." << std::endl;
        }
    }

    for (Branch* b: trees) {
        b = nullptr;
        delete b;
    }

    return 0;
}
