#include "Graph.h"

Graph::Graph(int size) : size(size)
{
    m = new int*[size];
    for (int i = 0; i < size; ++i) {
        m[i] = new int[size];
    }

    d = new int[size];
    visited = new bool[size];

    for (int i = 0; i < size; i++) {
        d[i] = std::numeric_limits<int>::max();
        visited[i] = false;
    }
    d[0] = 0;
}

Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete[] m[i];
    }
    delete[] m;
    delete[] d;
    delete[] visited;
}

void Graph::readMatrix()
{
    int s;
    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> s;
            m[i][j] = s;
        }
    }
}

void Graph::findShortestDistances()
{
    int minIndex;
    int min;

    for (int count = 0; count < size - 1; count++) {
        min = std::numeric_limits<int>::max();
        for (int i = 0; i < size; i++) {
            if (!visited[i] && d[i] < min) {
                min = d[i];
                minIndex = i;
            }
        }

        visited[minIndex] = true;

        for (int i = 0; i < size; i++) {
            if (!visited[i] && m[minIndex][i] && d[minIndex] != std::numeric_limits<int>::max() &&
                d[minIndex] + m[minIndex][i] < d[i]) {
                d[i] = d[minIndex] + m[minIndex][i];
            }
        }
    }
}

void Graph::printDistances()
{
    std::cout << "\nShortest distances IS \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Distance " << i + 1 << "--> " << d[i] << std::endl;
    }
}
