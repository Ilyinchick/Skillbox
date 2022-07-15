#pragma once

#include "IGraph.h"
#include <iostream>

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> graph;

public:
    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    bool containsVertex(int vertex) const override;

    std::vector<std::vector<int>> getGraph() const;

    MatrixGraph(std::vector<std::vector<int>> _graph) {
        for (int i = 0; i < _graph.size(); i++) {
            std::vector<int> str;
            for (int j = 0; j < _graph[i].size(); j++) {
                str.push_back(_graph[i][j]);
            }
            graph.push_back(str);
        }
    }

};
