#pragma once

#include "Contact.h"
#include <vector>


class Phone {
    std::vector<Contact> phoneBook;

public:
    void add();

    void call();

    void sms();

    bool findByNumber(std::string number);

    bool findByName(std::string name);

};

