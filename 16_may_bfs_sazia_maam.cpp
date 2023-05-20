#include<bits/stdc++.h>
using namespace std;
int adj[100][100];
int mark[100];
int distance[100];
void initadj(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            adj[i][j]=0;
        }
    }
}
void initmark(){
    for(int i=0;i<100;i++) mark[i]=0;
}

void initdistance(){

}

void initparent(){
    for(int i=0;i<100;i++) distance[i]=-1;
}

void bfs(int start){
    queue<int> q;//initializing the queue
    q.push(start);
    while(q.size()!=0){
       int king=q.front();
       q.pop();
       cout<<"The King is "<<king<<endl;;
    for(int i=0;i<100;i++){
        if(adj[king][i]==1&&mark[i]==0) {
                q.push(i);
                mark[i]=1;//if you have become king once you won't be king again
                distance[i]=distance[king]+1;
            }
        }
    }
}
int main(){
    initadj();
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y]=1;
    }
    int start;
    cin>>start;
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            cout<<adj[i][j]<<" ";//to print the adjacent amtrix
        }cout<<endl;
    }cout<<endl;
    bfs(start);
    return 0;
}
/*
output:
4 3
0 1
0 2
1 3
0
0 1 1 0
0 0 0 1
0 0 0 0
0 0 0 0

The King is 0
The King is 1
The King is 2
The King is 3
*/
