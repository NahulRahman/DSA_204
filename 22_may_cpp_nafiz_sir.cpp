#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=9;
    int v[n];
    int g[n][n];
    int color[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        v[i]=i;
        color[i]=0;
    }
    queue<int>q;
    q.push(8);
    color[8]=1;
    g[8][7]=1;
     g[8][6]=1;
      g[7][1]=1;
       g[7][2]=1;
        g[7][5]=1;
         g[6][3]=1;
          g[6][4]=1;
           g[6][0]=1;
    while(!q.empty())
    {
        int k=q.front();
        cout<<"k:"<<k<<endl;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(g[k][i]==1 && color[i]==0)
            {
                q.push(i);
                color[i]=i;
            }
        }
        color[k]=2;

    }
}
