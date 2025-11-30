#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int maxSquare(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // keep track of the next row values
    vector<int> dp(m + 1, 0);

    int ans = 0, prev = 0;

    // iteratively traverse all the cell in the matrix
    for (int i = n - 1; i >= 0; i--)
    {
        // reset diagonal at start of each row
        prev = 0;

        for (int j = m - 1; j >= 0; j--)
        {
            // store down cell value, dp[i + 1][j]
            int temp = dp[j];

            // curr cell value is 0, can't contribute to the square
            if (mat[i][j] == 0)
                dp[j] = 0;

            // pick the possible largest square for the curr cell, from right, down and diagonal
            else
                dp[j] = 1 + min({dp[j], dp[j + 1], prev});

            // update with the max length
            ans = max(ans, dp[j]);

            // diagonal for next column
            prev = temp;
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