#include<bits/stdc++.h>
using namespace std;

int tc,nodes,u,v,w,farthestNode,mx;
vector<int> tree[30001], weight[30001];
bool vislog[30001];
int dist[30001];

void dfs(int x)
{
    vislog[x]=true;
    for(int i=0;i<tree[x].size();++i)
    {
        int vertex=tree[x][i];
        if(vislog[vertex]==false)
        {
            dist[vertex]=weight[x][i]+dist[x];
            if(dist[vertex]>mx)
            {
                mx=dist[vertex];
                farthestNode=vertex;
            }
            dfs(vertex);
        }

    }
}

int main()
{
    cin>>tc;
    for(int t=1;t<=tc;++t)
    {
        memset(tree,NULL,sizeof(tree));
        memset(weight,NULL,sizeof(weight));


        memset(vislog,false,sizeof(vislog));
        memset(dist,0,sizeof(dist));

        cin>>nodes;
        for(int i=0;i<nodes-1;++i)
        {
            cin>>u>>v>>w;
            tree[u].push_back(v);
            tree[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);

        }

        mx=-1;
        dfs(0);

        memset(vislog,false,sizeof(vislog));
        memset(dist,0,sizeof(dist));
        mx=-1;
        dfs(farthestNode);

        cout<<"Case "<<t<<": "<<dist[farthestNode]<<endl;

    }

}
/*
2
5
0 1 3
0 2 5
1 3 2
1 4 4
3
0 1 2
1 2 3
output:
Case 1: 9
Case 2: 5

Explanation:

In the first case, there are 5 nodes in the tree. The edges and weights are provided as input.
The program performs two depth-first searches: first to find the farthest node from the starting node (0),
and then to find the distance from the farthest node to the starting node. The output for the first case is Case 1: 9.
In the second case, there are 3 nodes in the tree.
Similarly, the program finds the farthest node from the starting node (0) and calculates the distance from the farthest node to the starting node.
 The output for the second case is Case 2: 5.
*/
