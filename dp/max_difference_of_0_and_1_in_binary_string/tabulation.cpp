#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int maxDifference(string &s)
{
    int n = s.size();

    vector<int> dp(n, INT_MIN);

    // fill the first value of the dp table
    dp[0] = (s[0] == '0' ? 1 : -1);

    int best = dp[0];

    // itertate and explore every substring
    for (int i = 1; i < n; i++)
    {
        // '0' -> +1, '1' -> -1
        int val = (s[i] == '0') ? 1 : -1;

        // either include the curr value in the substring or start a new substring from the curr value(exclude)
        dp[i] = max(val, val + dp[i - 1]);

        // pick the best one
        best = max(best, dp[i]);
    }

    return best;
}

int main()
{
    string S = "11000010001";
    cout << maxDifference(S) << endl;
    return 0;
}