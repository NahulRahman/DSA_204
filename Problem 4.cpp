#include<bits/stdc++.h>
using namespace std;

int row,col,oil;
char oilDeposits[101][101];
bool vislog[101][101]; // keep track of which points have been visited

int changeX[8]={1,0,1,-1,1,-1,-1,0};
int changeY[8]={0,1,1,1,-1,-1,0,-1};


void dfs(int i,int j)
{
    for(int k=0;k<8;++k)
    {
        int newx=i+changeX[k];
        int newy=j+changeY[k];

        if(newx<0 or newx>row-1 or newy<0 or newy>col-1)
            continue;
        else if(vislog[newx][newy]==true or oilDeposits[newx][newy]!='@')
            continue;
        vislog[newx][newy]=true;
        dfs(newx,newy);
    }
}

int main()
{
    while(cin>>row>>col)
    {
        if(row==0)
            break;
        oil=0;
        memset(vislog,false,sizeof(vislog)); //setting vislog to false for every test case

        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                cin>>oilDeposits[i][j];
            }
        }

        // traverse the whole 2D array and call dfs for each unvisited @ found
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(vislog[i][j]==false and oilDeposits[i][j]=='@')
                    {
                        ++oil; //count how many times dfs is being called!
                        vislog[i][j]=true;
                        dfs(i,j);
                    }
             }
        }

        cout<<oil<<"\n";
   }
}
/*
3 5
1 0 1 0 1
0 0 1 1 0
1 0 1 0 1
5 5
0 0 0 0 1
1 0 1 1 0
0 0 0 0 1
1 0 1 1 0
1 1 1 1 1
0 0
output:
4
5
In the input, the numbers represent the presence of oil deposits.
'1' indicates the presence of an oil deposit, and '0' indicates the absence of an oil deposit.
The output represents the number of connected components (oil deposits) in each test case.

Note: The input and output may vary depending on the specific test cases provided.
*/
