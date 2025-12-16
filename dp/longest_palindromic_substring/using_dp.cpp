#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

string getLongestPal(string &s)
{
    int n = s.size();

    // 2d dp[] -> stores the status of the substring(i...j) whether it is a plaindrome or not
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0, maxLen = 1;

    // substring of length is always palindrome
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // check for substrings of length 2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            if (maxLen == 1)
            {
                start = i;
                maxLen = 2;
            }
        }
    }

    // check for substrings with length 3 to n
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            // character matches and substring(i + 1....j - 1) is already a palindrome ->
            // so substring(i...j) will also be a palindrome
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;

                // update with the max length substring
                if (len > maxLen)
                {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    // return the longest plaindromic substring
    return s.substr(start, maxLen);
}

int main()
{
    string s = "forgeeksskeegfor";
    cout << getLongestPal(s) << endl;
    return 0;
}