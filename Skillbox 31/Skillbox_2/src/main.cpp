#include <iostream>

#include "ListGraph.h"
#include "MatrixGraph.h"

int main() {
    std::vector<int> vertices;

    MatrixGraph* m = new MatrixGraph({ {0, 1, 0},
                                             {0, 0, 1},
                                             {0, 1, 0}});

    ListGraph* l = new ListGraph({new Vertex(1, {2}),
                                        new Vertex(2, {3}),
                                        new Vertex(3, {2})});

    ListGraph* l2 = new ListGraph(*m);

    MatrixGraph* m2 = new MatrixGraph(*l);

    m2->GetPrevVertices(2, vertices);

    for (int i: vertices) std::cout << i << " ";

    return 0;
}

