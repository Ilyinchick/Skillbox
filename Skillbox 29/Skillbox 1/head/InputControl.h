#pragma once
#include <vector>
#include <iostream>


class InputControl {
public:
    static bool ifContains(std::vector<std::string> vec, std::string word) {
        for (std::string s: vec) {
            if (word == s) return true;
        }
        return false;
    }
};

