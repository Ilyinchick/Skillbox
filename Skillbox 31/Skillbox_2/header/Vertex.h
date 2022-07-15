#pragma once

#include <vector>
#include <iostream>

class Vertex {
    int name;
    std::vector<int> list;

public:
    Vertex(int _name, std::vector<int> _list) : name(_name) {
        for(int i: _list) {
            list.push_back(i);
        }
    }

    int getName() const;

    std::vector<int> getList() const;

    void addEdgeToVertexList(int i);
};
