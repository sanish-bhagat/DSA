#include <bits/stdc++.h>
using namespace std;

int longestPalinSubseqRec(string &s, int low, int high)
{
    // base case: traversed the whole string -> return 0
    if (low > high)
        return 0;

    // on the same position, one character which will be always same
    if (low == high)
        return 1;

    // character matches -> explore the rest of the string
    if (s[low] == s[high])
        return longestPalinSubseqRec(s, low + 1, high - 1) + 2;

    // return the max of both the recursive calls
    return max(longestPalinSubseqRec(s, low + 1, high), longestPalinSubseqRec(s, low, high - 1));
}

//! TC is O(2 ^ n)
//! SC is O(n)

int longestPalinSubseq(string &s)
{
    // recursively start the traversal from both the ends and count the LPS
    return longestPalinSubseqRec(s, 0, s.size() - 1);
}

int main()
{
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}