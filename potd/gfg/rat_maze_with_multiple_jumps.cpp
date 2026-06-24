#include <bits/stdc++.h>
using namespace std;

// Helper function to find path using DFS and Memoization
bool solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &ans, vector<vector<int>> &dp)
{

    int n = mat.size();

    // Out of bounds
    if (i >= n || j >= n)
        return false;

    // Destination reached
    if (i == n - 1 && j == n - 1)
    {
        // Mark destination in path
        ans[i][j] = 1;
        return true;
    }

    // Check if current cell is a blocked cell
    if (mat[i][j] == 0)
        return false;

    // Memoization: if already calculated, return stored result
    if (dp[i][j] != -1)
        return dp[i][j];

    // Mark current cell as part of the answer path
    ans[i][j] = 1;

    int jump = mat[i][j];

    // Shortest jumps first (try 1 step, then 2 steps, etc.)
    for (int step = 1; step <= jump; step++)
    {

        // Try moving right first
        if (solve(i, j + step, mat, ans, dp))
        {
            return dp[i][j] = 1;
        }

        // Try moving down if moving right fails
        if (solve(i + step, j, mat, ans, dp))
        {
            return dp[i][j] = 1;
        }
    }

    // Backtrack: unmark cell if it leads to a dead end
    ans[i][j] = 0;

    return dp[i][j] = 0;
}

//! TC is O(n * n * max(mat))
//! SC is O(1)

vector<vector<int>> shortestDist(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Special case: 1x1 matrix
    if (n == 1)
        return {{1}};

    // Path matrix initialized to 0
    vector<vector<int>> ans(n, vector<int>(n, 0));

    // Blocked start cell check
    if (mat[0][0] == 0)
        return {{-1}};

    // Memoization table initialized to -1 (unvisited state)
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Start DFS from (0, 0), return [[-1]] if no path found
    if (!solve(0, 0, mat, ans, dp))
        return {{-1}};

    return ans;
}

void print2dArray(vector<vector<int>> &arr)
{
    for (auto &row : arr)
    {
        for (auto &cell : row)
            cout << cell << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {{2, 1, 0, 0}, {3, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 0, 1}};

    // Get shortest path matrix
    vector<vector<int>> result = shortestDist(mat);

    print2dArray(result);

    return 0;
}