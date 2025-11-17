#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, 0);

    // itertaively traverse for every length and
    // check if performing the cut will gives us the maximum segments, then make the cut
    for (int i = 1; i <= n; i++)
    {
        // curr length >= x and previous result for dp[i - x] is valid -> then perform the cut
        if (i >= x && dp[i - x] != -1)
            dp[i] = max(dp[i], 1 + dp[i - x]);

        // same check for y
        if (i >= y && dp[i - y] != -1)
            dp[i] = max(dp[i], 1 + dp[i - y]);

        // same check for z
        if (i >= z && dp[i - z] != -1)
            dp[i] = max(dp[i], 1 + dp[i - z]);

        // no valid cut was found for length i
        if (dp[i] == 0)
            dp[i] = -1;
    }

    // no valid cut on rod fo length n
    if (dp[n] == -1)
        return -1;

    // return the max cut on the rod
    return dp[n];
}

int main()
{

    int n = 11;
    int x = 2, y = 3, z = 5;

    cout << maximizeTheCuts(n, x, y, z);

    return 0;
}