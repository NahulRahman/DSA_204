#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int city = q.front();
        q.pop();

        for (int neighbor : graph[city]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int countWaterSupplyStations(int n, int m, vector<pair<int, int>>& roads) {
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < m; i++) {
        int x = roads[i].first;
        int y = roads[i].second;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            BFS(graph, visited, i);
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    int waterSupplyStations = countWaterSupplyStations(n, m, roads);
    cout << waterSupplyStations << endl;

    return 0;
}

