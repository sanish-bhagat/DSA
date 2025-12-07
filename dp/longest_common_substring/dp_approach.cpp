#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int maxCommStr(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    // 2d dp[] to keep track of lengths of longest common suffixes of substring
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int res = 0;

    // itertaively generate all the pair of indexes
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // character matches -> include it in the curr suffix of the substring
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            // character not matches -> start a new substring
            else
                dp[i][j] = 0;
        }
    }

    return res;
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "practicewritegeekscourses";
    cout << maxCommStr(s1, s2) << endl;
    return 0;
}