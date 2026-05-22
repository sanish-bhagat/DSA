#include <bits/stdc++.h>
using namespace std;

// check fo in-bound cells
bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    // mark the cell as visited
    grid[i][j] = 0;

    // moving directions
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    // try all possible directions
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if (isValid(nx, ny, n, m) && grid[nx][ny] == 1)
            dfs(nx, ny, grid);
    }
}

int cntOnes(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    // for every 1 encountered in the boundary, we start dfs and remove the connected one's
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
            dfs(i, 0, grid);

        if (grid[i][m - 1] == 1)
            dfs(i, m - 1, grid);
    }

    // for every 1 encountered in the boundary, we start dfs and remove the connected one's
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1)
            dfs(0, j, grid);

        if (grid[n - 1][j] == 1)
            dfs(n - 1, j, grid);
    }

    // count the remaining 1's
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 0, 0, 1}, {0, 1, 1, 0, 1, 0}, {0, 0, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 1}};
    int ans = cntOnes(grid);
    cout << ans << "\n";

    return 0;
}