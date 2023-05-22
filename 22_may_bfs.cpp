#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
int mark[100];
int lvl[100];
int parent[100];
void inadj()
{
    for(int i=0;i<100;i++)
    for(int j=0;j<100;j++)
    arr[i][j]=0;
}
void inmark()
{
    for(int i=0;i<100;i++)
   // for(int j=0;j<100;j++)
    mark[i]=0;
}
void inlvl()
{
    for(int i=0;i<100;i++)
   // for(int j=0;j<100;j++)
    lvl[i]=0;
}
void inparent()
{
    for(int i=0;i<100;i++)
   // for(int j=0;j<100;j++)
    parent[i]=-1;
}
void bfs(int start)
{
    queue<int>q;
    q.push(start);
   // parent[0]=start;
    while(q.size()!=0)
    {
         int king=q.front();
         q.pop();
         cout<<king<<' ';
        for(int i=0;i<5;i++)
        {
            if(arr[king][i]==1 && mark[i]!=1)
            {
                q.push(i);
                mark[i]=1;
                lvl[i]=lvl[king]+1;
                parent[i]=king;
            }
        }
    }
}
int main()
{
   inadj();
   inmark();
   inlvl();
   inparent();
   int n,e;
   cin>>n>>e;
   for(int i=0; i<e; i++)
   {
        int x,y;
        cin>>x>>y;
        arr[x][y]=1;
   }
   int start;
   cin>>start;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
        cout<<arr[i][j]<<' ';
        cout<<endl;
   }
   bfs(start);
}
