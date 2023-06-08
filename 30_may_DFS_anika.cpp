#include<bits/stdc++.h>
using namespace std;
int count_=0;
 int g[5][5]={0};
    int v[5];
    int color[5]={0};
    int dist[5]={0};
void dfs_visit(int k)
{
    cout<<k<< " "<<dist[k]<<endl;
    color[k]=1;
    for(int i=0;i<5;i++)
    {
        if(g[k][i]==1 && color[i]==0)
        {
            dist[i]=dist[k]+1;
            dfs_visit(i);
        }
    }
    color[k]=2;
}
void parent()
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
    {
        if(g[i][j]==1)
            cout<<j<<"->"<<i<<endl;
    }
}
int main()
{

    g[0][1]=1;
    g[0][2]=1;
    g[1][4]=1;
    g[1][3]=1;
    dist[0]=0;
    dfs_visit(0);
    parent();
}
