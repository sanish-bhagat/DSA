#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int longestPalinSubseq(string &s)
{
    int n = s.size();

    // 2d dp[] -> stores the length of the LPS of substring from s[i] to s[j]
    vector<vector<int>> dp(n, vector<int>(n));

    // iteratively explore the string
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            // same position, therefore same character
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            // character matches
            if (s[i] == s[j])
            {
                // only two characters present in the substring
                if (i + 1 == j)
                    dp[i][j] = 2;

                // or else, use previously computed results
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            }

            // character doesn't matches -> pick the max by either excluding i or j
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // return the max length of the LPS in string s
    return dp[0][n - 1];
}

int main()
{
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}