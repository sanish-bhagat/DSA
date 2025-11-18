#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int lcs(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    // 2d dp[][]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // iterativelly fill the dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // character matches
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            // character doesn't matches
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();

    cout << lcs(s1, s2) << endl;

    return 0;
}