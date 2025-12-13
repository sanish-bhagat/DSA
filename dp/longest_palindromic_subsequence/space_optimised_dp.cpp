#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int longestPalinSubseq(string &s)
{
    int n = s.size();

    // prev -> dp[i + 1][j], curr -> dp[i][j]
    vector<int> prev(n), curr(n);

    // iteratively traverse through the substring
    for (int i = n - 1; i >= 0; i--)
    {
        // single character -> always palindrome
        curr[i] = 1;

        for (int j = i + 1; j < n; j++)
        {
            // character matches -> use dp[i + 1][j - 1] value for computation,
            // i.e add 2 to the length of the palindrome
            if (s[i] == s[j])
                curr[j] = prev[j - 1] + 2;

            // character doesn't matches -> pick max either by excluding i or j
            else
                curr[j] = max(curr[j - 1], prev[j]);
        }

        // update the previous state by the current state of the dp
        prev = curr;
    }

    // return the LPS of the string s
    return prev[n - 1];
}

int main()
{
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}