#include "Branch.h"

int main() {
    std::srand(std::time(nullptr));
    std::vector<Branch *> trees;
    std::string name;
    int count = 0;

    for (int i = 0; i < 1; i++) {
        Branch *tree = new Branch();
        trees.push_back(tree);
        tree = nullptr;
        delete tree;
    }

    for (Branch *b: trees) {
        b->fillTree();
    }

    std::cout << "Enter a habitat's name: " << std::endl;
    std::cin >> name;

    for (Branch *b: trees) {
        if (b->searchBranch(name) != nullptr) {
            b->searchBranch(name)->searchBigBranch()->countOfNeighbors(&count);
            count -= 1;
            std::cout << name << " has " << count << " neighbors." << std::endl;
        } else {
            std::cout << "There is no such habitat." << std::endl;
        }
    }

    return 0;
}
