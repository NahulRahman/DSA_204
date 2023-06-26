#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Structure to represent a chess cell
struct Cell {
    int row;
    int col;

    Cell(int r, int c) : row(r), col(c) {}
};

// Function to check if a cell is valid and within the chessboard limits
bool isValidCell(int row, int col) {
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

// Function to get the minimum number of moves required for the knight to reach the destination
int getMinMoves(Cell start, Cell dest) {
    // Offsets for the knight's possible moves
    int rowOffsets[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int colOffsets[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // Create a visited map to keep track of visited cells
    unordered_map<int, unordered_map<int, bool>> visited;

    // Create a map to store the parent cell for each visited cell
    unordered_map<int, unordered_map<int, Cell>> parent;

    // Create a queue for BFS traversal
    queue<Cell> q;

    // Initialize the starting cell as visited
    visited[start.row][start.col] = true;

    // Enqueue the starting cell
    q.push(start);

    // Perform BFS traversal
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        // If the current cell is the destination, return the minimum number of moves
        if (curr.row == dest.row && curr.col == dest.col) {
            return parent[curr.row][curr.col].row;
        }

        // Explore all possible moves from the current cell
        for (int i = 0; i < 8; i++) {
            int newRow = curr.row + rowOffsets[i];
            int newCol = curr.col + colOffsets[i];

            // Check if the new cell is valid and not visited
            if (isValidCell(newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = curr;
                q.push(Cell(newRow, newCol));
            }
        }
    }

    // If the destination cell cannot be reached, return -1
    return -1;
}

// Function to print the path from the starting cell to the destination cell
void printPath(Cell start, Cell dest) {
    vector<Cell> path;
    Cell curr = dest;

    // Traverse the parent map to build the path
    while (curr.row != start.row || curr.col != start.col) {
        path.push_back(curr);
        curr = parent[curr.row][curr.col];
    }

    // Print the minimum number of moves
    cout << path.size() << endl;

    // Print the path in reverse order
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << static_cast<char>('A' + path[i].row) << path[i].col + 1;

        if (i > 0) {
            cout << "->";
        }
    }

    cout << endl;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string startCell, destCell;
        cin >> startCell >> destCell;

        // Convert the cell positions to row and column numbers
        Cell start(startCell[0] - 'A', startCell[1] - '1');
        Cell dest(destCell[0] - 'A', destCell[1] - '1');

        // Get the minimum number of moves and print the path
        int minMoves = getMinMoves(start, dest);
        printPath(start, dest);
    }

    return 0;
}

