#include <bits/stdc++.h>
using namespace std;

int lcsRec(string s1, string s2, int n, int m, vector<vector<int>> &memo)
{
    // base case -> any of the two strings becomes empty return 0
    if (n == 0 || m == 0)
        return 0;

    // already computed  subproblem
    if (memo[n][m] != -1)
        return memo[n][m];

    // character matches -> recurse for the remaining
    if (s1[n - 1] == s2[m - 1])
        return memo[n][m] = 1 + lcsRec(s1, s2, n - 1, m - 1, memo);

    // character not matches -> take max of the two recursive calls
    else
        return memo[n][m] = max(lcsRec(s1, s2, n - 1, m, memo), lcsRec(s1, s2, n, m - 1, memo));
}

//! TC is O(n * m)
//! SC is O(n * m)

int lcs(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    // 2d[][] memo to keep track of computations
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    return lcsRec(s1, s2, n, m, memo);
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