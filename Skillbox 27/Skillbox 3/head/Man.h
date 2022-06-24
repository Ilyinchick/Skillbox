#pragma once

#include <iostream>
#include <vector>


class Man {
    std::string name;
    int id;

    static int countEntities;

public:

    Man() {
        this->id = countEntities;
        countEntities += 1;
        this->name = "Unnamed";
    }

    void setName(std::string name);

    std::string getName();

    void setId(int inId);

    int getId();

    void print();

    void increase();

    static void setCount(int count);

    static int getCount();
};

