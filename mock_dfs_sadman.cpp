#include<bits/stdc++.h>
using namespace std;


int color[100]; int g[100][100];  int t[100];
int v, e;


void dfs(int k)
{
    color[k]=1;
    for(int i=0; i<v ;i++)
    {
        if(g[k][i]==1 && color[i]==0)
        {
            dfs(i);
        }
    }
    color[k]=2;


}
int main()
{



    cin>>v>>e;

    memset(color, 0, sizeof(color));
    memset(t, 0, sizeof(t));
    memset(g, 0, sizeof(g));


    for(int i=0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x][y]=1;
    }
    int stations=0;
    for(int i=0; i<v; i++)
    {
       if(color[i]==0)
       {
        stations++;
        dfs(i);

       }
    }

    cout<<stations;



}
