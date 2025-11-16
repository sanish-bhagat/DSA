#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countWays(int n, int k)
{

    // base case
    if (n == 1)
        return k;

    // base case
    if (n == 2)
        return k * k;

    // 1d[] for tablulation
    vector<int> dp(n + 1, 0);

    // fill the table with already known values
    dp[1] = k, dp[2] = k * k;

    // iteratively fill the table, with the no. of ways
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
    }

    // return the total ways to paint 'n' fences
    return dp[n];
}

int main()
{

    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}