#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, string s, vector<vector<int>> &memo)
{
    // base case
    if (i == 0 || j == 0)
        return 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    // character matches and are at different indices
    if (s[i - 1] == s[j - 1] && i != j)
        return memo[i][j] = 1 + helper(i - 1, j - 1, s, memo);

    // character doesn't matches or are at the same index
    return memo[i][j] = max(helper(i - 1, j, s, memo), helper(i, j - 1, s, memo));
}

//! TC is O(n * n)
//! SC is O(n * n)

int longestRepeatingSubsequence(string s)
{
    int n = s.length();

    // 2d memo[][] -> to store computed values during recursion
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    return helper(n, n, s, memo);
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}