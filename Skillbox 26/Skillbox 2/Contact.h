#pragma once

#include <string>
#include <iostream>

class Contact {

    std::string name;
    std::string number;

public:

    static Contact createContact();

    std::string getName();

    std::string getNumber();

};

