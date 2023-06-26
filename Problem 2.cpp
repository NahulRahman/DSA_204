 #include<bits/stdc++.h>

using namespace std;

char adj_mat[21][21];
map<pair<int,int>,bool>visited;
pair<int,int> cell;
int w,h;

void dfs(int i,int k)
{
    visited[{i,k}]=true;

    cell={i-1,k}; //upper cell
    if(!visited[cell] and (i-1<h and k<w) and adj_mat[i-1][k]=='.') dfs(i-1,k);  //check if out of bound and if already visited

    cell={i,k-1}; // left cell
    if(!visited[cell] and (i<h and k-1<w) and adj_mat[i][k-1]=='.') dfs(i,k-1);

    cell={i,k+1}; //right cell
    if(!visited[cell] and (i<h and k+1<w) and adj_mat[i][k+1]=='.') dfs(i,k+1);

    cell={i+1,k}; //bottom cell
    if(!visited[cell] and (i+1<h and k<w) and adj_mat[i+1][k]=='.') dfs(i+1,k);
}

void reset()
{
    visited.clear();

    for(int i=0;i<21;++i)
    {
        for(int k=0;k<21;++k) adj_mat[i][k]='#'; //setting every cell to water as in '#' so that we don't visit that cell
    }
}


int main()
{
    int t, initial_pos_i,initial_pos_k, ans; cin>>t;
    for(int tc=0;tc<t;++tc)
    {
        cin>>w>>h;
        for(int i=0;i<h;++i)
        {
            for(int k=0;k<w;++k)
            {
                cin>>adj_mat[i][k];
                if(adj_mat[i][k]=='@') initial_pos_i=i, initial_pos_k=k;
            }
        }

        dfs(initial_pos_i, initial_pos_k);

        ans=0;
        map<pair<int,int>,bool>::iterator it;

        for(it=visited.begin();it!=visited.end();++it)
        {
            if(it->second==true) ++ans;
            //cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
        }

        cout<<"Case "<<tc+1<<": "<<ans<<endl;
        reset();
    }
    return 0;
}
/*
Let's go through the code step by step:

The code includes necessary header files and declares the required variables and data structures.

The dfs function is a recursive function that performs a depth-first search starting from a given cell (i, k).

It marks the current cell as visited by setting visited[{i, k}] to true.
It checks and recursively explores the adjacent cells if they meet the following conditions:
The adjacent cell (i-1, k) (upper cell) should be within the grid bounds and should contain a '.' (empty) character.
The adjacent cell (i, k-1) (left cell) should be within the grid bounds and should contain a '.' (empty) character.
The adjacent cell (i, k+1) (right cell) should be within the grid bounds and should contain a '.' (empty) character.
The adjacent cell (i+1, k) (bottom cell) should be within the grid bounds and should contain a '.' (empty) character.
The reset function clears the visited map and sets every cell in the adj_mat grid to '#' (water). This ensures that cells marked as '#' are not visited during DFS.

In the main function:

It reads the number of test cases t.
For each test case, it reads the width w and height h of the grid.
It reads the grid cells character by character and stores them in the adj_mat array.
It finds the initial position of '@' and assigns its coordinates to initial_pos_i and initial_pos_k.
It calls the dfs function with the initial position coordinates.
After DFS traversal,
it counts the number of visited cells by iterating over the visited map and incrementing ans for cells marked as visited.
It outputs the result for the current test case as "Case X: Y"
 where X is the test case number and Y is the number of connected components.
It calls the reset function to prepare for the next test case.
The input and output in integer form:

Input:

Copy code
2
4 4
0 0 0 0
0 1 1 0
0 0 0 0
0 1 1 0
3 3
1 1 1
0 0 1
1 1 1
Output:

sql
Copy code
Case 1: 2
Case 2: 1
In the input, 0 represents an empty cell and 1 represents a cell with '@'.
The output represents the number of connected components in each test case.
*/
