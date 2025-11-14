#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int maxGold(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 2D[][] dp table
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // fill the last column with given last column gold values
    for (int i = 0; i < n; i++)
        dp[i][m - 1] = mat[i][m - 1];

    // fill table from second last column to first
    for (int y = m - 2; y >= 0; y--)
    {
        // can move in three directions, pick the max one
        for (int x = 0; x < n; x++)
        {
            int rightUpper = (x > 0) ? dp[x - 1][y + 1] : 0;

            int right = dp[x][y + 1];

            int rightLower = (x < n - 1) ? dp[x + 1][y + 1] : 0;

            dp[x][y] = mat[x][y] + max(max(rightUpper, right), rightLower);
        }
    }

    // find the max in first column
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i][0]);

    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}};

    cout << maxGold(mat) << endl;
    return 0;
}