#include <bits/stdc++.h>
using namespace std;

int helper(int i, int j, string s)
{
    // base case -> any of the two index becomes 0 -> return 0
    if (i == 0 || j == 0)
        return 0;

    // character matches at different indices -> add 1 to the result
    if (s[i - 1] == s[j - 1] && i != j)
        return 1 + helper(i - 1, j - 1, s);

    // character doesn't matches or the indices are not same -> pick the max of the two recursive calls
    return max(helper(i - 1, j, s), helper(i, j - 1, s));
}

//! TC is O(2 ^ n)
//! SC is O(n)

int longestRepeatingSubsequence(string s)
{
    int n = s.length();

    return helper(n, n, s);
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}