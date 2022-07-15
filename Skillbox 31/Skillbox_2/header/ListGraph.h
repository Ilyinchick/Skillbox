#pragma once

#include "Vertex.h"
#include "IGraph.h"
#include <iostream>

class ListGraph : public IGraph {
    std::vector<Vertex*> graph;

public:
    ~ListGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    bool containsVertex(int vertex) const override;

    ListGraph(std::vector<Vertex*> _graph) {
        for (Vertex* v: _graph) {
            graph.push_back(v);
        }
    }

    ListGraph(const IGraph &other) {

    }

};
