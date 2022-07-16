#include "ListGraph.h"

void ListGraph::AddEdge(int from, int to) {
    if (containsVertex(from) && containsVertex(to)) {
        for (Vertex *v: graph) {
            if (v->getName() == from) v->addEdgeToVertexList(to);
        }
    } else {
        std::cout << "There is no such vertexes in this graph." << std::endl;
    }
}

int ListGraph::VerticesCount() const {
    return graph.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (containsVertex(vertex)) {
        for (Vertex *v: graph) {
            if (v->getName() == vertex) {
                for (int i: v->getList()) {
                    vertices.push_back(i);
                }
            }
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (containsVertex(vertex)) {
        for (Vertex *v: graph) {
            for (int i: v->getList()) {
                if (i == vertex) vertices.push_back(v->getName());
            }
        }
    }
}

bool ListGraph::containsVertex(int vertex) const {
    for (Vertex *v: graph) {
        if (v->getName() == vertex) return true;
    }
    return false;
}

ListGraph::~ListGraph() {
    for (Vertex *v: graph) delete v;
}

std::vector<Vertex *> ListGraph::getGraph() const {
    return graph;
}


