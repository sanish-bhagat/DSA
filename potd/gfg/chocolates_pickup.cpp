#include <bits/stdc++.h>
using namespace std;

int maxChocolateRec(int row, int col1, int col2, vector<vector<int>> &grid,
                    vector<vector<vector<int>>> &dp)
{
    int n = grid.size(), m = grid[0].size();

    // base case
    if (row == n)
        return 0;

    // base case
    if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m)
        return 0;

    // already computed subproblem
    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    // moving directions
    vector<int> dir = {-1, 0, 1};
    int maxVal = 0;

    // traverse through directions
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int d1 = dir[i];
            int d2 = dir[j];

            // get the max value through traversing on different directions
            maxVal = max(maxVal, maxChocolateRec(row + 1, col1 + d1, col2 + d2, grid, dp));
        }
    }

    // include the max chocolate that robot1 can pick from curr cell
    maxVal += grid[row][col1];

    // if R1 and R2 are on not same cell -> then pick the curr cell chocolate through R2
    if (col1 != col2)
        maxVal += grid[row][col2];

    // store and return the max chocolate for curr cell
    return dp[row][col1][col2] = maxVal;
}

//! TC is O(n * m * m)
//! SC is O(n * m * m)

int maxChocolate(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    // 3d dp table -> keep tracks of curr state for {row, col for R1, col for R2}
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    // recurse on the grid matrix to find the max chocolate
    return maxChocolateRec(0, 0, m - 1, grid, dp);
}

int main()
{
    vector<vector<int>> grid = {
        {4, 1, 2},
        {3, 6, 1},
        {1, 6, 6},
        {3, 1, 2}};
    cout << maxChocolate(grid);
}