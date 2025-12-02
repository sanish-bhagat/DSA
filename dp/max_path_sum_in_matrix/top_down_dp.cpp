#include <bits/stdc++.h>
using namespace std;

int maxSumRec(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    // base case: out of bound -> invalid moves
    if (j < 0 || j >= mat[0].size())
        return 1e-9;

    // base case: reached beyond last row -> end of path
    if (i == mat.size())
        return 0;

    // already computed subproblem
    if (dp[i][j] != -1)
        return dp[i][j];

    // recursively move to three directions
    int down = maxSumRec(i + 1, j, mat, dp);
    int left = maxSumRec(i + 1, j - 1, mat, dp);
    int right = maxSumRec(i + 1, j + 1, mat, dp);

    // include the max sum of the three moves in the curr path
    return dp[i][j] = mat[i][j] + max({down, left, right});
}

//! TC is O(n * m)
//! SC is O(n * m)

int maximumPath(vector<vector<int>> &mat)
{
    int sum = 0;

    int n = mat.size(), m = mat[0].size();

    // 2d memo[][] to store the sum of path
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // start from every column of the first row and pick the path with the max sum
    for (int j = 0; j < m; j++)
        sum = max(sum, maxSumRec(0, j, mat, dp));

    return sum;
}

int main()
{

    // Input matrix
    vector<vector<int>> mat = {{10, 10, 2, 0, 20, 4},
                               {1, 0, 0, 30, 2, 5},
                               {0, 10, 4, 0, 2, 0},
                               {1, 0, 2, 20, 0, 4}};

    // Output the maximum path sum
    cout << maximumPath(mat) << endl;
    return 0;
}