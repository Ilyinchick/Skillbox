#include "Dancing.h"

void Dancing::addTalent(std::vector<std::string> *vec) {
    if (!InputControl::ifContains(*vec, "dance")) vec->push_back("dance");
}
