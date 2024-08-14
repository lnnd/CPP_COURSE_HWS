#include "Graph.h"
#include <queue>
#include <unordered_map>

//TODO, STUDENTS: Implement this func
void Graph::addEdge(unsigned x, unsigned y)
{
    auto& neighbors = adjacencyList[x];
    if (std::find(neighbors.begin(), neighbors.end(), y) == neighbors.end()) {
        neighbors.push_back(y);
    }
}

//TODO, STUDENTS: Implement modified BFS algo to return path from start to destination only
//no need to traverse the whole Graph
std::vector<unsigned> Graph::bfs(unsigned start, unsigned destination)
{
    std::unordered_map<unsigned, bool> visited; // Tracking visited peaks
    std::unordered_map<unsigned, unsigned> previous; // Tracking previous peaks along the way
    std::queue<unsigned> queue; // Queue for graph traversal

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        unsigned current = queue.front();
        queue.pop();

        if (current == destination) {
            // Recovering the path from destination to start
            std::vector<unsigned> path;
            for (unsigned at = destination; at != start; at = previous[at]) {
                path.push_back(at);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end()); // Turning the path around
            return path;
        }

        // Processing the neighbors of the current vertex
        for (unsigned neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                queue.push(neighbor);
                visited[neighbor] = true;
                previous[neighbor] = current;
            }
        }
    }

    return {}; // // Return an empty path if no path is found
}
