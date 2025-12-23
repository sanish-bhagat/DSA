#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int disarrange(int n)
{
    // 1d dp[]
    vector<int> dp(n + 1, 0);

    // base cases
    dp[1] = 0, dp[2] = 1;

    // fill the dp[] in bottom-up manner
    for (int i = 3; i <= n; i++)
    {
        // two cases for every i element:

        // case1: 
        int placed = dp[i - 2];

        // case2: 
        int notPlaced = dp[i - 1];

        // total choices for i element
        dp[i] = (i - 1) * (placed + notPlaced);
    }

    // total count of valid disarrangments possible
    return dp[n];
}

int main()
{
    int n = 4;
    cout << disarrange(n);
    return 0;
}