#pragma once

#include "Talent.h"

class Counting : protected Talent {

protected:
    void addTalent(std::vector<std::string>* vec);

    Counting() {};

};
