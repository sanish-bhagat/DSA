#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();

    if (n + m != s3.size())
        return false;

    // 2d dp[]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

    // s1 and s2 is empty -> can form empty s3
    dp[0][0] = true;

    // s2 is empty
    for (int j = 1; j <= m; j++)
        dp[0][j] = (s2[j - 1] == s3[j - 1]) && dp[0][j - 1];

    // s1 is empty
    for (int i = 1; i <= n; i++)
        dp[i][0] = (s1[i - 1] == s2[i - 1]) && dp[i - 1][0];

    // fill the rest of dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int k = i + j - 1;

            // character of s3 can be formed -> either using character from s1 or s2
            dp[i][j] = (s1[i - 1] == s3[k] && dp[i - 1][j]) || (s2[j - 1] == s3[k] && dp[i][j - 1]);
        }
    }

    // return if s3 can be formed by interleaving of s1 and d2
    return dp[n][m];
}

int main()
{
    string s1 = "AAB";
    string s2 = "AAC";
    string s3 = "AAAABC";
    cout << (isInterleave(s1, s2, s3) ? "true" : "false") << endl;
    return 0;
}