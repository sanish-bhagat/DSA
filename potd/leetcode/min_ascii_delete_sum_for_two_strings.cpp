#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int minDeleteSum(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    // 1d dp[]
    vector<int> dp(m + 1, 0);

    // base case: delete all char from s2
    for (int j = 1; j <= m; j++)
        dp[j] = dp[j - 1] + s2[j - 1];

    // traverse the string and fill the dp table in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        // dp[i - 1][0]
        int prev = dp[0];

        // delete char from s1
        dp[0] += s1[i - 1];

        // traverse the 2nd string
        for (int j = 1; j <= m; j++)
        {
            // store dp[i - 1][j]
            int temp = dp[j];

            // character matches -> no cost needed to delete
            if (s1[i - 1] == s2[j - 1])
                dp[j] = prev;

            // remove character either from s1 or s2 and pick the min delete cost
            else
                dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);

            // update the state of prev
            prev = temp;
        }
    }

    // return the min delete cost required to make both the strings exactlyy equal
    return dp[m];
}

int main()
{
    string s1 = "sea", s2 = "eat";
    cout << minDeleteSum(s1, s2);
}