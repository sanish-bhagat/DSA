#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * sum)
//! SC is O(n * sum)

int count(vector<int> &coins, int sum)
{
    int n = coins.size();

    // 2D dp table
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    // target sum is 0 and only way to make change- by not selecting the coin
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // add no. of ways to make change without using the current coin
            dp[i][j] += dp[i - 1][j];

            if (j - coins[i - 1] >= 0)
            {
                // add the no. of ways to make change using the curr coin
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}