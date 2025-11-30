#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int maxSquare(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 2d dp[][]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    // itertate through every cell in the matrix
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {

            // cell value is 0: can;t contribute to the square, set 0 in dp table and skip the computations
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            // pick the largest possible sqaure which can be formed for the curr cell by using values from right, down, bottom-right
            dp[i][j] = 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});

            // update the result with the max length the of the square sub-matrix
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat =
        {{0, 1, 1, 0, 1},
         {1, 1, 0, 1, 0},
         {0, 1, 1, 1, 0},
         {1, 1, 1, 1, 0},
         {1, 1, 1, 1, 1},
         {0, 0, 0, 0, 0}};
    cout << maxSquare(mat) << endl;

    return 0;
}