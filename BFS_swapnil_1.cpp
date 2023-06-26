#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    string name;
    string path;
    int clicks;

    Node(string name, string path, int clicks) : name(name), path(path), clicks(clicks) {}
};

void bfs(const unordered_map<string, vector<string>>& filesystem, const string& target) {
    queue<Node> q;
    q.push(Node("C:", "C:", 0));

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.name == target) {
            cout << curr.path << endl;
            cout << curr.clicks << endl;
            return;
        }

        if (filesystem.find(curr.name) != filesystem.end()) {
            for (const string& child : filesystem.at(curr.name)) {
                string childPath = curr.path + "\\" + child;
                int childClicks = curr.clicks + 2;
                q.push(Node(child, childPath, childClicks));
            }
        }
    }

    cout << "File not found" << endl;
    cout << -1 << endl;
}

int main() {
    int e;
    cin >> e;

    unordered_map<string, vector<string>> filesystem;

    for (int i = 0; i < e; i++) {
        string parent, child;
        cin >> parent >> child;
        filesystem[parent].push_back(child);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string target;
        cin >> target;
        bfs(filesystem, target);
    }

    return 0;
}
