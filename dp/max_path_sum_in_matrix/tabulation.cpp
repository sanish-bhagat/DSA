#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int maximumPath(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 2d dp[][]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // fill the first row of the dp table same as the first row of given matrix
    for (int j = 0; j < m; j++)
        dp[0][j] = mat[0][j];

    // iteratively fill the dp table
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // for every cell, we can come from the following three directions
            int up = dp[i - 1][j];
            int left = (j > 0) ? dp[i - 1][j - 1] : 0;
            int right = (j < m - 1) ? dp[i - 1][j + 1] : 0;

            // pick up the max of all the three moves and include in the curr path
            dp[i][j] = mat[i][j] + max({up, left, right});
        }
    }

    // find the max sum of all the paths
    int sum = 0;
    for (int j = 0; j < m; j++)
        sum = max(sum, dp[n - 1][j]);

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