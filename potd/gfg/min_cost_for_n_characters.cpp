#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minCost(int n, int i, int d, int c)
{
    // No characters are required.
    if (n == 0)
        return 0;

    // One insert is needed to obtain a single character.
    if (n == 1)
        return i;

    // dp[x] stores the minimum cost to obtain exactly x characters.
    vector<int> dp(n + 1, 0);

    dp[1] = i;

    // Compute the minimum cost for every length from 2 to n.
    for (int x = 2; x <= n; x++)
    {
        if (x % 2 == 0)
        {
            // Even length:
            // 1) Insert one character after reaching x - 1.
            // 2) Copy-paste from x / 2 characters.
            dp[x] = min(dp[x - 1] + i, dp[x / 2] + c);
        }
        else
        {
            // Odd length:
            // 1) Insert one character after reaching x - 1.
            // 2) Copy-paste from (x + 1) / 2 characters,
            //    then delete the extra character.
            dp[x] = min(dp[x - 1] + i, dp[(x + 1) / 2] + c + d);
        }
    }

    return dp[n];
}

int main()
{

    int n = 9, i = 10, d = 1, c = 1;

    cout << minCost(n, i, d, c);

    return 0;
}