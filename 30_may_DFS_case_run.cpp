#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 5;

void dfs(int g[MAX_SIZE][MAX_SIZE], int n, int start)
{
    stack<int> s;
    int visited[MAX_SIZE] = {0};
    int dist[MAX_SIZE] = {0};

    s.push(start);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (visited[current] == 0)
        {
            visited[current] = 1;
            cout << current << " " << dist[current] << endl;
        }

        for (int i = 0; i < n; i++)
        {
            if (g[current][i] == 1 && visited[i] == 0)
            {
                dist[i] = dist[current] + 1;
                s.push(i);
            }
        }
    }
}

void insertValue(int g[MAX_SIZE][MAX_SIZE], int& n)
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
        n++;
    }
    else
    {
        cout << "Invalid vertex position!" << endl;
    }
}

void deleteValue(int g[MAX_SIZE][MAX_SIZE], int& n)
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

void printElements(int g[MAX_SIZE][MAX_SIZE], int n)
{
    cout << "Elements in the graph:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

void printParent(int g[MAX_SIZE][MAX_SIZE], int n)
{
    cout << "Parent of each vertex:" << endl;
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
    int n;
    cout << "Enter the number of vertices (maximum " << MAX_SIZE << "): ";
    cin >> n;

    int g[MAX_SIZE][MAX_SIZE] = {0};

    cout << "Enter the graph elements (0 or 1):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. DFS Traversal" << endl;
        cout << "2. Insert a value after a vertex" << endl;
        cout << "3. Delete a value" << endl;
        cout << "4. Print the elements in the graph" << endl;
        cout << "5. Print the parent of each vertex" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                int start;
                cout << "Enter the starting vertex for DFS traversal: ";
                cin >> start;
                cout << "\nDFS Traversal:" << endl;
                dfs(g, n, start);
                break;
            case 2:
                insertValue(g, n);
                break;
            case 3:
                deleteValue(g, n);
                break;
            case 4:
                printElements(g, n);
                break;
            case 5:
                printParent(g, n);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
