#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &grid, int r, int c)
{
    int row = grid.size();
    int col = grid[0].size();

    // node is in-bound and is a land -> then it is safe to visit the curr node
    return (r >= 0) && (r < row) && (c >= 0) && (c < col) && (grid[r][c] == 'L');
}

void dfs(vector<vector<char>> &grid, int r, int c)
{

    // mark the curr node as 'W'
    grid[r][c] = 'W';

    // moves for all 8 directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 1, 0, -1, 1, -1, 1, 0};

    // explore all the 8 directions
    for (int k = 0; k < 8; k++)
    {
        int nr = r + dr[k];
        int nc = c + dc[k];

        // if curr node is safe to visit -> go for the dfs traversal
        if (isSafe(grid, nr, nc))
            dfs(grid, nr, nc);
    }
}

//! TC is O(n * m)
//! SC is O(1)

int countIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    // count no. of islands
    int count = 0;

    // iteratively traverse every node
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            // curr node is a land
            if (grid[r][c] == 'L')
            {
                dfs(grid, r, c);

                // increase the island count
                count++;
            }
        }
    }

    return count;
}

int main()
{
    // Updated grid with 'L' for land and 'W' for water
    vector<vector<char>> grid = {{'L', 'W', 'W', 'W', 'W'},
                                 {'W', 'L', 'W', 'W', 'L'},
                                 {'L', 'W', 'W', 'L', 'L'},
                                 {'W', 'W', 'W', 'W', 'W'},
                                 {'L', 'W', 'L', 'L', 'W'}};

    cout << countIslands(grid) << endl;

    return 0;
}