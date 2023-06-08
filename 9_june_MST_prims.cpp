#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    vector<pair<int, pair<int, int>>> G;
    vector<pair<int, pair<int, int>>> T;
    int parent[10];

public:
    Graph(int vertex) {
        for (int i = 0; i < vertex; i++) {
            parent[i] = i;
        }
    }

    void AddEdge(int u, int v, int w) {
        G.push_back({w, {u, v}});
    }

    int find_set(int i) {
        if (i == parent[i])
            return i;
        else
            return find_set(parent[i]);
    }

    void Union_set(int u, int v) {
        parent[u] = v;
    }

    void prim() {
        sort(G.begin(), G.end());
        vector<bool> included(G.size(), false);
        vector<int> key(G.size(), INT_MAX);

        // Start with the first vertex
        key[0] = 0;

        for (int count = 0; count < G.size(); count++) {
            int u = minKey(key, included);
            included[u] = true;

            int uRep = find_set(G[u].second.first);
            int vRep = find_set(G[u].second.second);

            if (uRep != vRep) {
                T.push_back(G[u]);
                Union_set(uRep, vRep);
            }

            key[u] = INT_MAX; // Mark vertex as included
        }
    }

    int minKey(const vector<int>& key, const vector<bool>& included) {
        int minKey = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < G.size(); v++) {
            if (!included[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void print() {
        for (auto edge : T) {
            cout << edge.second.first << " => " << edge.second.second << " => " << edge.first << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.AddEdge(0, 1, 2);
    g.AddEdge(1, 4, 1);
    g.AddEdge(0, 2, 1);
    g.AddEdge(2, 3, 3);
    g.AddEdge(0, 3, 4);
    g.AddEdge(1, 3, 3);
    g.AddEdge(1, 2, 2);
    g.AddEdge(2, 4, 4);
    g.prim();
    g.print();

    return 0;
}
