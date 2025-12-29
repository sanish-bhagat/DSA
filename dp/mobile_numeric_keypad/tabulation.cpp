#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int getCount(int n)
{
    // 3d dp[]
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, 0)));

    // initialise values for remianing length = 1
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[1][i][j] = 1;
        }
    }

    // values for cell * and #
    dp[1][3][0] = 0;
    dp[1][3][2] = 0;

    // directions for traversal at every curr cell
    vector<vector<int>> dir = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // traverse for every remaining length from (2...n)
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // cell value is * or #
                if (i == 3 && (j == 0 || j == 2))
                    continue;

                // traverse in every direction from the curr cell
                for (auto d : dir)
                {
                    int x = i + d[0], y = j + d[1];

                    // if after visiting the direction, the cell is in-bound ->
                    // calculate the answer for all next 5 cells
                    if (x >= 0 && x < 4 && y >= 0 && y < 3)
                        dp[k][i][j] += dp[k - 1][i][j];
                }
            }
        }
    }

    int ans = 0;

    // calculate ans from each cell
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
            ans += dp[n][i][j];
    }

    return ans;
}

int main()
{

    int n = 1;
    cout << getCount(n);
    return 0;
}