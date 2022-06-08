#pragma once
#include "Contact.h"
#include <vector>


class Phone {
    std::vector<Contact> phoneBook;

public:
    void add();

    void call();

    void sms();

    void print();
};

