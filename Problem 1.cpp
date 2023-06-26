#include<bits/stdc++.h>
using namespace std;

vector<int> adjacent[9];
map<int,int> parent;
vector<bool> vislog;
vector<int> discoveryTime,traversedTime;
int tme;

void dfs(int x)
{
    vislog[x]=true;
    ++tme;
    discoveryTime.push_back(tme);
    cout<<x<<' ';
    for(int j=0;j<adjacent[x].size();++j)
    {
        if(vislog[adjacent[x][j]]==false)
        {
            dfs(adjacent[x][j]);
        }
    }
    ++tme;
    traversedTime.push_back(tme);
}

void printParent()
{
    cout<<endl<<endl;
    for(map<int,int>:: iterator i=parent.begin();i!=parent.end();++i)
    {
        cout<<"Parent of "<<i->first<<" is: "<<i->second<<endl;
    }
}

void showDiscoveryTime()
{
    cout<<endl<<endl;
    for(int i=0;i<9;++i)
    {
        cout<<"Discovery time of vertex "<<i<<" is: "<<discoveryTime[i]<<endl;
    }
}

void showTraversedTime()
{
    cout<<endl<<endl;
     for(int i=0;i<9;++i)
    {
        cout<<"Traversed time of vertex "<<i<<" is: "<<traversedTime[i]<<endl;
    }

}

int main()
{
    for(int i=0;i<9;++i)
        vislog.push_back(false);

    adjacent[0].push_back(1); parent[1]=0;
    adjacent[0].push_back(2); parent[2]=0;
    adjacent[0].push_back(3); parent[3]=0;
    adjacent[1].push_back(4); parent[4]=1;
    adjacent[1].push_back(5); parent[5]=1;
    adjacent[2].push_back(6); parent[6]=2;
    adjacent[3].push_back(7); parent[7]=3;
    adjacent[3].push_back(8); parent[8]=3;

    cout<<"Order of traversal: ";
    for(int i=0;i<9;++i)
    {
        if(vislog[i]==false)
            dfs(i);
    }
    printParent();
    showDiscoveryTime();
    showTraversedTime();

}
/*Order of traversal: 0 1 4 5 2 6 3 7 8

Parent of 1 is: 0
Parent of 2 is: 0
Parent of 3 is: 0
Parent of 4 is: 1
Parent of 5 is: 1
Parent of 6 is: 2
Parent of 7 is: 3
Parent of 8 is: 3


Discovery time of vertex 0 is: 1
Discovery time of vertex 1 is: 2
Discovery time of vertex 2 is: 3
Discovery time of vertex 3 is: 5
Discovery time of vertex 4 is: 8
Discovery time of vertex 5 is: 9
Discovery time of vertex 6 is: 12
Discovery time of vertex 7 is: 13
Discovery time of vertex 8 is: 15


Traversed time of vertex 0 is: 4
Traversed time of vertex 1 is: 6
Traversed time of vertex 2 is: 7
Traversed time of vertex 3 is: 10
Traversed time of vertex 4 is: 11
Traversed time of vertex 5 is: 14
Traversed time of vertex 6 is: 16
Traversed time of vertex 7 is: 17
Traversed time of vertex 8 is: 18

Process returned 0 (0x0)   execution time : 53.286 s
Press any key to continue.*/
