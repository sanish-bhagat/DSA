#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(n * k)

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    // 3d dp matrix -> dp[i][k][buy]
    // i -> curr day, k -> transactions left, buy = 1 if we can buy or else 0
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

    // fill the dp table in bottom-up manner
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= k; j++)
        {
            // if we can buy, either buy or skip the day
            dp[i][j][1] = max(dp[i + 1][j][0] - prices[i], dp[i + 1][j][1]);

            // if we can say, either sell or skip the day
            dp[i][j][0] = max(dp[i + 1][j - 1][1] + prices[i], dp[i + 1][j][0]);
        }
    }

    // return the max profit after k transactions
    return dp[0][k][1];
}

int main()
{
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};

    cout << maxProfit(prices, k);
    return 0;
}