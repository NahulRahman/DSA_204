//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#define V 8
int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, mindex;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min) min = key[v], mindex = v;
    return mindex;
}
int c=0,x=0;
void printprim(int parent[], int graph[V][V]){
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << " \t"<<graph[i][parent[i]]<<endl;
                 if(graph[i][parent[i]] !=0) c++;
          x=x+graph[i][parent[i]];
    }cout<<"total weight"<<x<<endl;
}

void prim(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++){
            key[i] = INT_MAX, mstSet[i] = false;
        }
    key[1] = 0;
    parent[1] = 1;
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++){
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) parent[v] = u, key[v] = graph[u][v];
            }
    }
    printprim(parent, graph);
}

int main(){
    int edg=9;
    int graph[V][V] = {0};
    graph[1][2]=28;
    graph[2][1]=28;
    graph[1][6]=10;
    graph[6][1]=10;
    graph[2][3]=16;
    graph[3][2]=16;
    graph[2][7]=14;
    graph[7][2]=14;
    graph[3][4]=12;
    graph[4][3]=12;
    graph[4][7]=18;
    graph[7][4]=18;
    graph[4][5]=22;
    graph[5][4]=22;
    graph[5][7]=24;
    graph[7][5]=24;
    graph[5][6]=25;
    graph[6][5]=25;
    prim(graph);
    cout<<"Number of cycles: "<<edg-c;
    return 0;
}
