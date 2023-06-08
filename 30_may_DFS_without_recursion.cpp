#include <bits/stdc++.h>
using namespace std;

int g[5][5] = {0};
int v[5];
int color[5] = {0};
int dist[5] = {0};

void dfs(int start)
{
    stack<int> s;
    s.push(start);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (color[current] == 0)
        {
            color[current] = 1;
            cout << current << " " << dist[current] << endl;
        }

        for (int i = 0; i < 5; i++)
        {
            if (g[current][i] == 1 && color[i] == 0)
            {
                dist[i] = dist[current] + 1;
                s.push(i);
            }
        }
        color[current] = 2;
    }
}

void parent()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (g[i][j] == 1)
            {
                cout << j << "->" << i << endl;
            }
        }
    }
}

int main()
{
    g[0][1] = 1;
    g[0][2] = 1;
    g[1][4] = 1;
    g[1][3] = 1;
    dist[0] = 0;
    dfs(0);
    parent();

    return 0;
}
