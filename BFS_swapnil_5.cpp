#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Function to generate binary strings of length up to n
void generateBinaryStrings(int n) {
    queue<string> q;
    q.push("0");
    q.push("1");

    for (int i = 1; i <= n; i++) {
        cout << "Length " << i << ": ";

        int size = q.size();
        for (int j = 0; j < size; j++) {
            string curr = q.front();
            q.pop();
            cout << curr << " ";

            q.push(curr + "0");
            q.push(curr + "1");
        }

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    generateBinaryStrings(n);

    return 0;
}
