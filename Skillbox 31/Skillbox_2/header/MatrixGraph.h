#pragma once

#include "IGraph.h"

class MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> graph;

    bool contains(const std::vector<int> &vec, const int &i);

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

    MatrixGraph(const IGraph &other) {
        for (int i = 0; i < other.VerticesCount(); i++) {
            std::vector<int> verticles, str;
            other.GetNextVertices(i + 1, verticles);
            for (int j = 0; j < other.VerticesCount(); j++) {
                if (contains(verticles, j + 1)) str.push_back(1);
                else str.push_back(0);
            }
            graph.push_back(str);
        }
    }
};
