#pragma once
#include <vector>
#include "Talent.h"


class Dog  {
    std::vector<Talent*> talents;

public:

    void showTalents();

    void addTalent(Talent* t);

};

