#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct City {
    string name;
    string country;
    bool isCapital;

    City(string name, string country, bool isCapital)
        : name(name), country(country), isCapital(isCapital) {}
};

void bfs(const unordered_map<string, vector<string>>& graph, const string& start) {
    unordered_map<string, string> countryMap;
    unordered_map<string, string> pathMap;
    unordered_map<string, int> distanceMap;

    queue<string> q;
    q.push(start);
    countryMap[start] = graph.at(start)[0];
    pathMap[start] = start;
    distanceMap[start] = 0;

    while (!q.empty()) {
        string city = q.front();
        q.pop();

        for (const string& neighbor : graph.at(city)) {
            if (countryMap.find(neighbor) == countryMap.end()) {
                q.push(neighbor);
                countryMap[neighbor] = countryMap[city];
                pathMap[neighbor] = pathMap[city] + " -> " + neighbor;
                distanceMap[neighbor] = distanceMap[city] + 100;
            }
        }
    }

    for (auto it = countryMap.begin(); it != countryMap.end(); ++it) {
        if (it->first != start) {
            cout << it->second << endl;
            cout << pathMap[it->first] << endl;
            cout << distanceMap[it->first] << " km" << endl;
        }
    }
}

int main() {
    int e;
    cin >> e;

    unordered_map<string, vector<string>> graph;

    for (int i = 0; i < e; i++) {
        string city1, city2, country;
        cin >> city1 >> city2 >> country;
        graph[city1].push_back(city2);
        graph[city2].push_back(city1);
        if (city1[0] >= 'A' && city1[0] <= 'Z') {
            graph[city1].push_back(country);
            graph[country].push_back(city1);
        }
        if (city2[0] >= 'A' && city2[0] <= 'Z') {
            graph[city2].push_back(country);
            graph[country].push_back(city2);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        if (graph.find(query) != graph.end()) {
            bfs(graph, query);
        } else {
            cout << "City not found" << endl;
        }
    }

    return 0;
}
