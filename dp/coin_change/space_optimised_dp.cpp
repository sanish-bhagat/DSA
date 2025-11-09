#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * sum)
//! SC is O(sum)

int count(vector<int> &coins, int sum)
{
    int n = coins.size();

    // dp table -> stores the no. of solutions for value i
    vector<int> dp(sum + 1);

    // base case- if given value is 0
    dp[0] = 1;

    // pick all the coins one by one and update the dp table
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];
    }

    return dp[sum];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}