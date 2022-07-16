#pragma once

#include "IGraph.h"
#include "Vertex.h"


class ListGraph : public IGraph {
    std::vector<Vertex*> graph;

public:
    ~ListGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    bool containsVertex(int vertex) const override;

    std::vector<Vertex*> getGraph() const;

    ListGraph(std::vector<Vertex*> _graph) {
        for (Vertex* v: _graph) {
            graph.push_back(v);
        }
    }

    ListGraph(const IGraph &_graph) {
        for (int i = 1; i <= _graph.VerticesCount(); i++) {
            std::vector<int> verticles;
            _graph.GetNextVertices(i, verticles);
            graph.push_back(new Vertex(i, {verticles}));
            verticles.clear();
        }
    }
};
