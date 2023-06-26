#include<bits/stdc++.h>
using namespace std;
int n = 9;

int main()
{
    int v[n];
    int g[n][n];
    int color[n];
    int parent[n];
    int dist[n];
    int i;
    for(i=0; i<n; i++)
    {
        v[i] = 0;
        color[i] = 0;
        parent[i] = 0;
        dist[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            g[i][j] = 0;
        }
    }
    g[0][1] = 1;
    g[0][2] = 1;
    g[0][3] = 1;
    g[1][4] = 1;
    g[1][5] = 1;
    g[2][3] = 1;
    g[2][6] = 1;
    g[3][7] = 1;
    g[3][8] = 1;
    g[7][8] = 1;
    int c = 0;
    stack<int>s;
    s.push(0);
    color[0] = 1;
    parent[0] = 0;
    v[0] = 1;
    while(!s.empty())
    {
        int k = s.top();
        cout<<k<<"\n";
        s.pop();
        for(i=0; i<n; i++)
        {
            if(g[k][i]==1 && color[i] == 0 && v[i]==0)
            {
                s.push(i);
                color[i] = 1;
                parent[i] = k;
                dist[i] = dist[k] + 1;
                v[i] = 1;
            }
            else if(g[k][i]==1 && v[i]==1 && parent[k]!=i)
            {
                c++;
                g[k][i] = 0;
            }
        }
        color[k] = 2;

    }
    cout<<"Number of cycles: "<<c<<"\n";
    for(i=0;i<n;i++)
    {
        if(parent[i]!=-1)
        {
            cout<<i<<" -> "<<parent[i]<<"\n";
        }
        if(parent[i]==-1)
        {
            cout<<i<<" -> "<<"NULL(since its the root)\n";
        }
    }

}
