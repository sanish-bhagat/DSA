#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countWays(int n)
{
    // point value to score
    vector<int> points = {3, 5, 10};

    // dp[i] = number of ways to get score i
    vector<int> dp(n + 1, 0);

    // base: 1 way to get score 0 (take nothing)
    dp[0] = 1;

    // iterate points
    for (int p : points)
    {
        // include it in the combination if we can include it
        for (int i = p; i <= n; i++)
        {
            dp[i] += dp[i - p];
        }
    }

    return dp[n];
}

int main()
{
    int n = 20;
    cout << countWays(n);
    return 0;
}