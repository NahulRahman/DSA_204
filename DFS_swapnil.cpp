#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = INT_MAX;

void dfs(const vvi& graph, int u, vi& visited) {
    visited[u] = 1;

    for (int v : graph[u]) {
        if (!visited[v])
            dfs(graph, v, visited);
    }
}

int getMinCost(const vvi& graph) {
    int n = graph.size();
    vi visited(n, 0);
    int minCost = 0;

    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            minCost++;
        }
    }

    return minCost;
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int n;
        cin >> n;

        vvi graph(n + 1);

        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(b);
            if (c == 1)
                graph[b].push_back(a);
        }

        int minCost = getMinCost(graph);

        cout << "Case " << caseNum << ": " << minCost << endl;
    }

    return 0;
}
