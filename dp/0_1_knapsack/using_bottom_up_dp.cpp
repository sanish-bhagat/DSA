#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * W)
//! SC is O(n * W)

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    // 2D matrix -> stores the max value
    // we can get using 'i' items such that the knapsack capcacity is 'j
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            // no item or the knapsack capacity is 0
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else
            {
                // either we include the curr item in the knapsack,
                // if including it does not lead to outer bound of curr bag weight capacity
                int pick = 0;

                if (wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];

                // or we exclude the curr item
                int notPick = dp[i - 1][j];

                // store the max-one in terms of value
                dp[i][j] = max(pick, notPick);
            }
        }
    }

    return dp[n][W];
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}