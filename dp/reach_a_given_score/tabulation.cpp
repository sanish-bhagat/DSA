#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    // points value
    vector<int> points = {3, 5, 10};

    // 2d dp[]
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    // 1 valid combination for score 0
    for (int j = 0; j <= 3; j++)
        dp[0][j] = 1;

    // itertivaly check for each score
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            // can include the curr point value in the curr combination
            if (i - points[j] >= 0)
                dp[i][j] = dp[i - points[j]][j] + dp[i][j + 1];

            // move to the next point value
            else
                dp[i][j] = dp[i][j + 1];
        }
    }

    // return the total valid combinations
    return dp[n][0];
}

int main()
{
    int n = 20;
    cout << countWays(n);
    return 0;
}