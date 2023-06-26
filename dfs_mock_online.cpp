#include<bits/stdc++.h>
using namespace std;
int ad[100][100];
int mark[100];
int dist[100];
int parent[100];
int visited[100];
void initadj()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            ad[i][j] = 0;
        }
    }
}
void initmark()
{
    int i;
    for(i=0;i<100;i++)
    {
        mark[i] = 0;
        visited[i] = 0;
    }
}
void initdist()
{
    int i;
    for(i=0;i<100;i++)
    {
        dist[i] = -1;
    }
}
void initparent()
{
    int i;
    for(i=0;i<100;i++)
    {
        parent[i] = -1;
    }
}
void bfs(int start,int n)
{
    queue<int> q;
    q.push(start);
    int king;
    while(q.size()!=0)
    {
        king = q.front();
        q.pop();
        cout<<king<<" ";
        for(int i=0;i<n;i++)
        {
            if(ad[king][i]==1 && mark[i]==0)
            {
                q.push(i);
                visited[i]=1;
                mark[i] = 1;
                dist[i] = dist[king]+1;
                parent[i] = king;
            }
        }
    }
}
int main()
{
    initadj();
    initmark();
    int n,e,i,j,c=0;
    while(1){
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        ad[x][y] = 1;
    }
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {   c++;
            bfs(i,n);
        }
    }
    cout<<"Number of water supply stations: "<<c<<"\n";
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<ad[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}
