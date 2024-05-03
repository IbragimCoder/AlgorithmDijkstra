#ifndef ALGORITHMDIJKSTRA_GRAPH_H
#define ALGORITHMDIJKSTRA_GRAPH_H

#include <iostream>
#include <vector>
#include <limits>

class Graph {
private:
    int size;
    int** m;
    int* d;
    bool* visited;
public:
    Graph(int size);
    ~Graph();
    void readMatrix();
    void findShortestDistances();
    void printDistances();
};


#endif
