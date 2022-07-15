#include <iostream>

#include "ListGraph.h"
#include "MatrixGraph.h"

int main() {
    std::vector<int> vertices;

    MatrixGraph* m = new MatrixGraph({ {0, 1, 0},
                                             {0, 0, 1},
                                             {0, 1, 0}});
    m->AddEdge(1, 3);
    m->GetNextVertices(1, vertices);
    for (int i: vertices) std::cout << i << std::endl;

    return 0;
}



//   std::vector<std::vector<int>> vec = m->getGraph();

//    for(int i = 0; i < vec[0].size(); i++) {
//        std::cout << vec[i][0] << " ";
//    }



//
//    ListGraph* l = new ListGraph({new Vertex(1, {2}),
//                                        new Vertex(2, {3}),
//                                        new Vertex(3, {})});
//
//    l->GetNextVertices(1, vertices);
//    for (int i: vertices) std::cout << i << "    ";
//    std::cout << std::endl;
//    vertices.clear();
//
//    l->AddEdge(1, 3);
//
//    l->GetNextVertices(1, vertices);
//    for (int i: vertices) std::cout << i << " ";
//    std::cout << std::endl;
//
//    std::cout << l->VerticesCount() << std::endl;