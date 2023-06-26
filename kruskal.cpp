#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;


}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first<<endl;

  }
  int c=0;
  for (int i = 0; i < T.size(); i++) {
        c=c+T[i].first;
     }
    cout <<"Minimum total cost : "<<c<< endl;
}
int main() {
  Graph g(10);
  g.AddWeightedEdge(3, 4, 1);
  g.AddWeightedEdge(6, 8, 2);
  g.AddWeightedEdge(2, 3, 2);
  g.AddWeightedEdge(1, 3, 3);
  g.AddWeightedEdge(1, 2, 4);
  g.AddWeightedEdge(2, 4, 5);
  g.AddWeightedEdge(3, 5, 6);
  g.AddWeightedEdge(4, 6, 7);
  g.AddWeightedEdge(5, 6, 8);
  g.AddWeightedEdge(6, 7, 9);
  g.kruskal();
  g.print();
  return 0;
}
/*
Edge : Weight
3 - 4 : 1
2 - 3 : 2
6 - 8 : 2
1 - 3 : 3
3 - 5 : 6
4 - 6 : 7
6 - 7 : 9

Process returned 0 (0x0)   execution time : 0.141 s
Press any key to continue.

*/
