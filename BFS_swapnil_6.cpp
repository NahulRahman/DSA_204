#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int value;
    vector<int> path;
};

void printConversionPath(const vector<int>& path) {
    int n = path.size();
    for (int i = 0; i < n; i++) {
        cout << path[i];
        if (i != n - 1)
            cout << " -> ";
    }
    cout << endl;
}

void bfs(int X, int Y) {
    queue<Node> q;
    Node start;
    start.value = X;
    start.path.push_back(X);
    q.push(start);

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.value == Y) {
            cout << curr.path.size() - 1 << endl;
            printConversionPath(curr.path);
            return;
        }

        Node next;
        next.path = curr.path;

        next.value = curr.value * 2;
        next.path.push_back(next.value);
        q.push(next);

        next.value = curr.value - 1;
        next.path.push_back(next.value);
        q.push(next);
    }
}

int main() {
    int X, Y;
    cin >> X >> Y;

    bfs(X, Y);

    return 0;
}
