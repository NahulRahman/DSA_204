#include<bits/stdc++.h>
using namespace std;

int n,cs;
char board[201][201];
int changeX[]={-1,-1,0,0,1,1};
int changeY[]={-1,0,-1,1,0,1};

void dfs(int x,int y)
{
    for(int k=0;k<6;++k)
    {
        int newx=x+changeX[k];
        int newy=y+changeY[k];

        if(newx<0 or newx>n-1 or newy<0 or newy>n-1)
            continue;
        else if(board[newx][newy]!='b')
            continue;
        board[newx][newy]='v';
        dfs(newx,newy);
    }

}

int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        ++cs;
        memset(board,NULL,sizeof(board));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>board[i][j];
            }
        }

        for(int i=0;i<n;++i)
            dfs(0,i);
        bool f=true;
        for(int i=0;i<n;++i)
        {
            if(board[n-1][i]=='v')
            {
                f=false;
                break;
            }
        }
        if(f)
            cout<<cs<<" W"<<endl;
        else
            cout<<cs<<" B"<<endl;


    }



}

/*
4
bbwb
wwbw
bbwb
bwww
4
bbwb
wwbw
bwwb
wwbb
The provided code is a program that determines the winner in a game played on a hexagonal board.
Each cell of the board is represented by a character, where 'b' represents black and 'w' represents white. The board is divided into hexagons,
and the goal is to connect the top edge of the board to the bottom edge using black cells only.
The program uses a depth-first search (DFS) algorithm to check if it is possible to connect the edges using only black cells.

Here's an explanation of what's happening in the code:

The code starts with including the necessary headers and defines the global variables.
The dfs function performs a depth-first search starting from the given position (x, y).
It checks the neighboring cells and recursively calls dfs for unvisited black cells.
The search is performed in six directions represented by changeX and changeY arrays.
In the main function, the program enters a loop that reads the input value n until it encounters a zero, indicating the end of the input.
For each test case, the program increments the cs variable to keep track of the test case number.
The board is initialized by reading the characters from the input and storing them in the board array.
The program starts the DFS from the top row of the board, calling dfs(0, i) for each column position.
After the DFS, the program checks if there is any 'v' (visited) cell in the last row (board[n-1][i]).
 If there is, it means black cells have successfully connected the top and bottom edges, and the variable f is set to false.
Based on the value of f, the program outputs the result: cs W if f is true (white wins) or cs B if f is false (black wins).
The loop continues until it encounters a zero, and the program terminates.
*/
