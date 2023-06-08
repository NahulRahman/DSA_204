#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 9;

void bfsTraversal(int g[MAX_SIZE][MAX_SIZE], int n)
{
    queue<int> q;
    int visited[MAX_SIZE] = {0};

    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int current = q.front();
        cout << "Visited vertex: " << current << endl;
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (g[current][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void insertValue(int g[MAX_SIZE][MAX_SIZE], int n)
{
    int vertex, value;
    cout << "Enter the vertex after which to insert: ";
    cin >> vertex;
    cout << "Enter the value to insert: ";
    cin >> value;

    if (vertex >= 0 && vertex < n)
    {
        for (int i = n - 1; i > vertex; i--)
        {
            g[vertex][i] = g[vertex][i - 1];
            g[i][vertex] = g[i - 1][vertex];
        }
        g[vertex][vertex + 1] = value;
        g[vertex + 1][vertex] = value;
    }
    else
    {
        cout << "Invalid vertex position!" << endl;
    }
}

void deleteValue(int g[MAX_SIZE][MAX_SIZE], int n)
{
    int value;
    cout << "Enter the value to delete: ";
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        if (g[i][i] == value)
        {
            for (int j = i; j < n - 1; j++)
            {
                g[j][j] = g[j + 1][j + 1];
                for (int k = j + 1; k < n - 1; k++)
                {
                    g[j][k] = g[j + 1][k + 1];
                    g[k][j] = g[k + 1][j + 1];
                }
            }
            n--;
            break;
        }
    }
}

void findParent(int g[MAX_SIZE][MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        int parent = -1;
        for (int j = 0; j < n; j++)
        {
            if (g[j][i] == 1)
            {
                parent = j;
                break;
            }
        }
        cout << "Parent of vertex " << i << ": " << parent << endl;
    }
}

int main()
{
    int n = 9;
    int g[MAX_SIZE][MAX_SIZE] = {0};

    g[8][7] = 1;
    g[8][6] = 1;
    g[7][1] = 1;
    g[7][2] = 1;
    g[7][5] = 1;
    g[6][3] = 1;
    g[6][4] = 1;
    g[6][0] = 1;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. BFS Traversal" << endl;
        cout << "2. Insert a value after a vertex" << endl;
        cout << "3. Delete a value" << endl;
        cout << "4. Find the parent of all vertices" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                bfsTraversal(g, n);
                break;
            case 2:
                insertValue(g, n);
                break;
            case 3:
                deleteValue(g, n);
                break;
            case 4:
                findParent(g, n);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << endl;
    }
}
