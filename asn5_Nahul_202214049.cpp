#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertex) {
        adjList.resize(vertex);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    vector<pair<int, int>> prim(int startVertex) {
        vector<pair<int, int>> minSpanningTree; // Stores the edges of the minimum spanning tree
        vector<bool> visited(adjList.size(), false); // Tracks visited vertices
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue to select edges with minimum weight

        // Start with the given startVertex
        pq.emplace(0, startVertex);

        while (!pq.empty()) {
            int currVertex = pq.top().second;
            int currWeight = pq.top().first;
            pq.pop();

            if (visited[currVertex]) {
                continue;
            }

            visited[currVertex] = true;
            if (currVertex != startVertex) {
                minSpanningTree.emplace_back(currVertex, currWeight);
            }

            // Explore adjacent vertices
            for (const auto& neighbor : adjList[currVertex]) {
                int neighborVertex = neighbor.first;
                int neighborWeight = neighbor.second;

                if (!visited[neighborVertex]) {
                    pq.emplace(neighborWeight, neighborVertex);
                }
            }
        }

        return minSpanningTree;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 4, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);

    vector<pair<int, int>> minSpanningTree = g.prim(0);

    for (const auto& edge : minSpanningTree) {
        cout << edge.first << " => " << edge.second << endl;
    }

    return 0;
}
