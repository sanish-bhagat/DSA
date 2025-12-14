#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int countPS(string &s)
{
    int n = s.size();

    // 2d dp[] -> count of palindromic subsequences in substring[i...j]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // substring with length(single character) of 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // explore every subsequence of len(2..n)
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;

            // character matches ->
            // try subsequences excluding left character + try subsequences excluding the right characters +
            // since character matches, +1 counts the palindrome formed by pairing s[i] and s[j]
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;

            // character doesn't matches
            // try sequences excluding left or right characters - remove doubly counted middle palindromes
            // once it is count during left recursion and once it is count during right recursion, so we remove the count once
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }

    // return the count of palindrome subsequences in the string s
    return dp[0][n - 1];
}

int main()
{
    string s = "aab";
    cout << countPS(s);
}