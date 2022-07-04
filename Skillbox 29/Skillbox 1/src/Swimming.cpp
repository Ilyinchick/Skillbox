#include "Swimming.h"

void Swimming::addTalent(std::vector<std::string> *vec) {
    if (!InputControl::ifContains(*vec, "swim")) vec->push_back("swim");
}
