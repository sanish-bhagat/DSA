#include <bits/stdc++.h>
using namespace std;

int bestEnding(int i, string &s, vector<int> &dp)
{
    // base case
    if (i == 0)
        return dp[i] = (s[i] == '0') ? 1 : -1;

    // already computed value
    if (dp[i] != INT_MIN)
        return dp[i];

    // '0' -> +1, '1' -> -1
    int val = (s[i] == '0') ? 1 : -1;

    // explore more substrings
    int prev = bestEnding(i - 1, s, dp);

    // pick the best value
    return dp[i] = max(val, val + prev);
}

//! TC is O(n * n)
//! SC is O(n)

int maxDifference(string &s)
{
    int n = s.size();

    // all are 1's
    if (count(s.begin(), s.end(), '1') == n)
        return -1;

    // 1d memo[] to track the value of substring
    vector<int> dp(n, INT_MIN);
    int ans = INT_MIN;

    // recursivelly explore all the substrings
    for (int i = 0; i < n; i++)
        ans = max(ans, bestEnding(i, s, dp));

    return ans;
}

int main()
{
    string S = "11000010001";
    cout << maxDifference(S) << endl;
    return 0;
}