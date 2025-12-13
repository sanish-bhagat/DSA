#include <bits/stdc++.h>
using namespace std;

int longestPalinSubseqRec(string s, int low, int high, vector<vector<int>> &memo)
{
    // base case: traversed the whole string -> return 0
    if (low > high)
        return 0;

    // on the same position, one character which will be always same
    if (low == high)
        return 1;

    // already computed subproblem
    if (memo[low][high] != -1)
        return memo[low][high];

    // character matches -> explore the rest of the string
    if (s[low] == s[high])
        return memo[low][high] = longestPalinSubseqRec(s, low + 1, high - 1, memo) + 2;

    // return the max of both the recursive calls
    return memo[low][high] = max(longestPalinSubseqRec(s, low + 1, high, memo), longestPalinSubseqRec(s, low, high - 1, memo));
}

//! TC is O(n * n)
//! SC is O(n * n)

int longestPalinSubseq(string &s)
{
    // 2d memo[] -> stores the length of the LPS of substring from s[low] to s[high]
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));

    return longestPalinSubseqRec(s, 0, s.size() - 1, memo);
}

int main()
{
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}