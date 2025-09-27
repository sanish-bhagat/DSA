#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int lps(int i, int j, string &s)
{
    // base case
    if (i == 0 || j == 0)
        return 0;

    //char match and indices are different
    if (s[i - 1] == s[j - 1] && i != j)
        return 1 + lps(i - 1, j - 1, s);

    //char does not match or indices are same
    else
        return max(lps(i - 1, j, s), lps(i, j - 1, s));
}

int longestRepeatingSubsequence(string &s)
{
    int n = s.length();
    return lps(n, n, s);
}

int main()
{
    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}