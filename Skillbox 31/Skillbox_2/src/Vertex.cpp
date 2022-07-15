#include "Vertex.h"

int Vertex::getName() const {
    return name;
}

std::vector<int> Vertex::getList() const {
    return list;
}

void Vertex::addEdgeToVertexList(int i) {
    bool f = true;
    for (int j: list) if (i == j) f = false;
    if (f) list.push_back(i);
}
