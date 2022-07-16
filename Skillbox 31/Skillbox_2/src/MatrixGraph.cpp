#include "MatrixGraph.h"
#include <assert.h>

MatrixGraph::~MatrixGraph() = default;

void MatrixGraph::AddEdge(int from, int to) {
    from--;
    to--;
    if (containsVertex(from) && containsVertex(to)) {
        if (graph[from][to] != 1) graph[from][to] = 1;
    }
}

int MatrixGraph::VerticesCount() const {
    return graph.size();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    vertex--;
    assert(vertex < graph[vertex].size());

    if (containsVertex(vertex)) {
        for(int i = 0; i <= graph[vertex].size(); i++) {
            if (graph[vertex][i] == 1) vertices.push_back(i+1);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    vertex--;
    assert(vertex < graph[vertex].size());
    if (containsVertex(vertex)) {

        for(int i = 0; i < graph[vertex].size(); i++) {
            if (graph[i][vertex] == 1) {
                vertices.push_back(i+1);
            }
//            for(int i = 0; i < vec[0].size(); i++) {
//                std::cout << vec[i][0] << " ";
//            }
        }
    }
}

bool MatrixGraph::containsVertex(int vertex) const {
    for (int i = 0; i < graph.size(); i++) {
        if (i == vertex) return true;
    }
    return false;
}

std::vector<std::vector<int>> MatrixGraph::getGraph() const {
    return graph;
}

bool MatrixGraph::contains(const std::vector<int> &vec, const int &i) {
    for (int j: vec) {
        if (j == i ) return true;
    }
    return false;
}

