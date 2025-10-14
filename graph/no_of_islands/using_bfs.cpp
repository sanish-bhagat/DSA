#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &vis)
{
    int row = grid.size();
    int col = grid[0].size();

    // node is in-bound and is a land and have not been visited yet -> then it is safe to visit the curr node
    return (r >= 0) && (r < row) && (c >= 0) && (c < col) && (grid[r][c] == 'L' && !vis[r][c]);
}

void bfs(vector<vector<char>> &grid, int sr, int sc, vector<vector<bool>> &vis)
{
    // mark the curr node as visited
    vis[sr][sc] = true;

    // moves for all 8 directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 1, 0, -1, 1, -1, 1, 0};

    queue<pair<int, int>> q;
    q.push({sr, sc});

    // bfs traversal
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // explore all the 8 directions
        for (int k = 0; k < 8; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            // if curr node is safe to visit -> mark the curr node as visited and
            // push it into the queue for further exploration
            if (isSafe(grid, nr, nc, vis))
            {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

//! TC is O(n * m)
//! SC is O(n * m)

int countIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    // visited matrix, to keep track of visited nodes
    vector<vector<bool>> vis(row, vector<bool>(col, false));

    // count no. of islands
    int count = 0;

    // iteratively traverse every node
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            // curr node is a land and not visited yet
            if (grid[r][c] == 'L' && !vis[r][c])
            {
                bfs(grid, r, c, vis);

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