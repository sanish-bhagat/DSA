#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int longestRepeatingSubsequence(string s)
{
    int n = s.length();

    // 2d dp[][] table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // iterate through all the characters in the string
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            // character matches and are at different indices
            if (s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // character doesn't matches or are at different indices
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}