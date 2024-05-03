#include "Graph.h"

int main()
{
    int size;
    std::cout << "size of the matrix: ";
    std::cin >> size;

    Graph g(size);

    g.readMatrix();
    g.findShortestDistances();
    g.printDistances();

    return 0;
}
