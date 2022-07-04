#include "Counting.h"

void Counting::addTalent(std::vector<std::string>* vec) {
    if (!InputControl::ifContains(*vec, "count")) vec->push_back("count");
}

