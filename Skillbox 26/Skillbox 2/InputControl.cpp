#pragma once
#include "InputControl.h"

bool checkNumber(std::string number) {
    if (number.length() != 12 || (number[0] != '+' || number[1] != '7')) return false;
    for (int i = 2; i < number.length(); i++) {
        if (number[i] < '0' || number[i] > '9') return false;
    }
    return true;
}
