#include<bits/stdc++.h>
#define edge pair<int,int>//vertex, t

using namespace std;
class Graph{
    vector<pair<int,edge>>G;
    vector<pair<int,edge>>T;
    int parent[10];
public:
        Graph(int vertex){
            for(int i=0;i<vertex;i++){
                parent[i]=i;
            }
        }
        void AddEdge(int u, int v, int w){
            G.push_back({w,{u,v}});
        }
        int find_set(int i){
            if (i==parent[i]) return i;
            else return find_set(parent[i]);
        }
        void Union_set(int u,int v){
            parent[u]=parent[v];//0 r parent akhon 1
        }
        void kruskal(){
            sort(G.begin(),G.end());
            int uRep,vRep,i;
            for(i=0;i<G.size();i++){
                uRep=find_set(G[i].second.first);//u
                vRep=find_set(G[i].second.second);//v
                if(uRep!=vRep){
                    T.push_back(G[i]/*weight*/);
                    Union_set(uRep,vRep);//Union_set(G[i].second.first,G[i].second.second); aida dile pura graph print hbe with weight
                }
            }
        }
        void print(){
            for(int i=0;i<T.size();i++){
                cout<<T[i].second.first<<"=>"<<T[i].second.second<<"=>"<<T[i].first<<endl;
            }
        }
};

int main(){
    //per vertex ke nijer disjoint set banai
    Graph g(5);
    g.AddEdge(0,1,2);
    g.AddEdge(1,4,1);
    g.AddEdge(0,2,1);
    g.AddEdge(2,3,3);
    g.AddEdge(0,3,4);
    g.AddEdge(1,3,3);
    g.AddEdge(1,2,2);
    g.AddEdge(2,4,4);
    g.kruskal();
    g.print();
}
