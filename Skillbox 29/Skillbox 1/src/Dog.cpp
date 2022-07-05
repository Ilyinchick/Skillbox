#include "Dog.h"

void Dog::showTalents() {
    for (Talent* t: talents) {
        t->doThing();
    }
}

void Dog::addTalent(Talent *t) {
    talents.push_back(t);
}

