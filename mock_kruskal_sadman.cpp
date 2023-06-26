#include<bits/stdc++.h>
using namespace std;

#define edge pair<int,int>
class Graph
{
    vector<pair<int,edge>> G;
    vector<pair<int,edge>> T;
    int parent[100];

public:


    Graph(int V)
    {
        for(int i=0; i<V;i++)
        {
            parent[i]=i;
        }

    }

    void AddEdge(int u, int v, int w)
    {
        G.push_back({w,{u,v}});

    }




    int find_set(int i)
    {
        if(i==parent[i])
            return i;
        else
        {
            return find_set(parent[i]);

        }

    }


    void Union_set(int u, int v)
    {
        parent[u]=parent[v];

    }



    void Kruskal()
    {

        sort(G.begin(), G.end());
        int uRep, vRep;
        for(int i=0; i<G.size(); i++)
        {
             uRep=find_set(G[i].second.first);
             vRep=find_set(G[i].second.second);
             if(uRep!=vRep)
            {
                T.push_back(G[i]);
                Union_set(uRep, vRep );


            }

        }


    }

    void print()
    {
        int weight=0;
        for(int i=0; i<T.size(); i++)
        {
            weight+=T[i].first;
            cout<<T[i].second.first<<"-------"<<T[i].second.second<<"   "<<T[i].first<<endl;

        }
        cout<<"Minimum total cost: "<<weight;
    }


};

int main()
{
    cout<<"Number of islands: ";
    int n;
    cin>>n;
    Graph g(n+1);
    int e;
    cout<<"Edges: ";
    cin>>e;
    for(int i=0; i<e; i++ )
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.AddEdge(u,v,w);
    }

    g.Kruskal();
    g.print();




}
