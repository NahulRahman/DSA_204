#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBicolorable(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> color(n, -1); // Initialize all vertices with no color
    color[start] = 0; // Assign the start vertex color 0

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr]) {
            if (color[neighbor] == -1) {
                // Assign a different color to the neighbor
                color[neighbor] = 1 - color[curr];
                q.push(neighbor);
            } else if (color[neighbor] == color[curr]) {
                // If the neighbor has the same color as the current vertex, the graph is not bicolorable
                return false;
            }
        }
    }

    return true; // All vertices are colored without any conflict
}

bool isBicolorableGraph(const vector<vector<int>>& graph) {
    int n = graph.size();

    for (int i = 0; i < n; i++) {
        if (!isBicolorable(graph, i))
            return false;
    }

    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (isBicolorableGraph(graph))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
