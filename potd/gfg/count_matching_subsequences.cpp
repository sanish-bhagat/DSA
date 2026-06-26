#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

//! TC is O(n * m)
//! SC is O(m)

int countWays(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    // 1d dp table
    vector<int> dp(m + 1, 0);

    // empty string can always be formed
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // traverse from right to left
        for (int j = m; j >= 1; j--)
        {
            // characters are same, include or exclude the curr character
            if (s1[i - 1] == s2[j - 1])
                dp[j] = (dp[j - 1] + dp[j]) % MOD;
        }
    }

    return dp[m];
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "gks";

    cout << countWays(s1, s2);

    return 0;
}