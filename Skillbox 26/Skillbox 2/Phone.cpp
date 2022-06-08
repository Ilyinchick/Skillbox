#include "Phone.h"

void Phone::add() {
    phoneBook.push_back(Contact::createContact());
}

void Phone::print() {
    std::cout << phoneBook.size();
}
