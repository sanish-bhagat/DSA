#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countWays(int n, int m)
{
    // Modulo value to prevent overflow
    int MOD = 1000000007;

    // dp[i] stores the number of ways
    // to tile a floor of length i
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        // If floor length is less than tile length,
        // tiles can only be placed horizontally
        if (i < m)
            dp[i] = 1;

        // If floor length equals tile length,
        // either all horizontal or all vertical
        else if (i == m)
            dp[i] = 2;

        // Apply recurrence relation
        else
            dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
    }

    // Return the answer for floor length n
    return dp[n];
}

int main()
{
    int n = 7, m = 4;

    cout << countWays(n, m);

    return 0;
}