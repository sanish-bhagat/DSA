#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n)

int countSubsequences(string s, int n)
{
    int MOD = 1e9 + 7;

    // dp[rem] stores the number of subsequences
    // having remainder rem modulo n.
    vector<int> dp(n, 0);

    // Process each digit of the string.
    for (char ch : s)
    {
        int digit = ch - '0';

        // Copy the previous DP state.
        vector<int> curr(dp);

        // Start a new subsequence with the current digit.
        curr[digit % n] = (curr[digit % n] + 1) % MOD;

        // Append the current digit to all existing subsequences.
        for (int rem = 0; rem < n; rem++)
        {
            int newRem = (rem * 10 + digit) % n;
            curr[newRem] = (curr[newRem] + dp[rem]) % MOD;
        }

        // Move to the next digit.
        dp = curr;
    }

    return dp[0];
}

int main()
{
    string s = "1234";
    int n = 4;

    cout << countSubsequences(s, n) << endl;

    return 0;
}