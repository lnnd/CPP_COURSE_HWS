#pragma once
#include <vector>
#include <list>
#include <map>

class Graph {
public:

    unsigned sizeX = 0;
    unsigned sizeY = 0;

    Graph(unsigned numVertices) 
    {
        //TODO, STUDENTS: Init internal structure (adjacency list or adjacency matrix) with numVertices size
        adjacencyList.resize(numVertices);
    }


    //TODO, STUDENTS: Implement this func
    void addEdge(unsigned x, unsigned y);

    //TODO, STUDNETS: Implement modified BFS algo to return path from start to destination only
    //no need to traverse the whole Graph
    std::vector<unsigned> bfs(unsigned start, unsigned destination);

private:
    std::vector<std::list<unsigned>> adjacencyList;
};

