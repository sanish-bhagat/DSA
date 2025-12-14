#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int countPS(string &s)
{
    int n = s.size();

    // 1d next[] -> dp[i + 1][*], curr[] = dp[i][*]
    vector<int> next(n, 0), curr(n, 0);

    // base case: single characters
    for (int i = 0; i < n; i++)
        next[i] = 1;

    // process in bottom-up manner
    for (int i = n - 1; i >= 0; i--)
    {
        // dp[i][i] = 1
        curr[i] = 1;

        for (int j = i + 1; j < n; j++)
        {
            // character matches ->
            // try subsequences excluding left character + try subsequences excluding the right characters +
            // since character matches, +1 counts the palindrome formed by pairing s[i] and s[j]
            if (s[i] == s[j])
                curr[j] = next[j] + curr[j - 1] + 1;

            // character doesn't matches
            // try sequences excluding left or right characters - remove doubly counted middle palindromes
            // once it is count during left recursion and once it is count during right recursion, so we remove the count once
            else
                curr[j] = next[j] + curr[j - 1] - next[j - 1];
        }

        // move dp one row up -> update the next row values by the current one
        next = curr;
    }

    // return the total count of palindromic subsequences in string s
    return next[n - 1];
}

int main()
{
    string s = "aab";
    cout << countPS(s);
}