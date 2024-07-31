#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <iostream>

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
    std::unordered_map<unsigned, bool> visited; // Отслеживание посещенных вершин
    std::unordered_map<unsigned, unsigned> previous; // Отслеживание предыдущих вершин на пути
    std::queue<unsigned> queue; // Очередь для обхода графа

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
        unsigned current = queue.front();
        queue.pop();

        if (current == destination) {
            // Восстанавливаем путь от destination до start
            std::vector<unsigned> path;
            for (unsigned at = destination; at != start; at = previous[at]) {
                path.push_back(at);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end()); // Переворачиваем путь
            return path;
        }

        // Обрабатываем соседей текущей вершины
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

