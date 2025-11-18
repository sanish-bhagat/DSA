#include <bits/stdc++.h>
using namespace std;

int lcsHelper(string s1, string s2, int n, int m)
{
    // base case -> any of the two string becomes empty return 0
    if (n == 0 || m == 0)
        return 0;

    // last character matches -> recurse for the remaining
    if (s1[n - 1] == s2[m - 1])
        return 1 + lcsHelper(s1, s2, n - 1, m - 1);

    // character not matches -> take max of the two recursive calls
    else
        return max(lcsHelper(s1, s2, n - 1, m), lcsHelper(s1, s2, n, m - 1));
}

//! TC is O(2 ^ min(n, m))
//! SC is O(min(m, n))

int lcs(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    return lcsHelper(s1, s2, n, m);
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