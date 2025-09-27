#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! Sc is O(n * n)

int lps(int i, int j, string &s, vector<vector<int>> &memo)
{

    // base case
    if (i == 0 || j == 0)
        return 0;

    //if value is computed return it
    if (memo[i - 1][j - 1] != -1)
        return memo[i - 1][j - 1];

    //char match and indices are different
    if (s[i - 1] == s[j - 1] && i != j)
        return memo[i - 1][j - 1] = 1 + lps(i - 1, j - 1, s, memo);

    return memo[i - 1][j - 1] = max(lps(i - 1, j, s, memo), lps(i, j - 1, s, memo));
}

int longestRepeatingSubsequence(string &s)
{

    int n = s.length();
    vector<vector<int>> memo(n, vector<int>(n, -1));

    return lps(n, n, s, memo);
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}