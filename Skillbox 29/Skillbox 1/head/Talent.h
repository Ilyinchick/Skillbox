#pragma once
#include <iostream>
#include <vector>
#include "InputControl.h"

class Talent {

protected:
    virtual void addTalent(std::vector<std::string>* vec) = 0;
};
