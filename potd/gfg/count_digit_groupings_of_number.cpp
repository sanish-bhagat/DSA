#include <bits/stdc++.h>
using namespace std;

//! TC is O(n^3)
//! Sc is O(n^2)

int validGroups(string &s)
{
    int n = s.size();

    // Maximum possible sum of digits for a
    // string of length n is 9 * n
    int maxSum = n * 9;

    // dp[i][prevSum] => number of ways to split
    // from index i with last group sum = prevSum
    vector<vector<int>> dp(n + 1, vector<int>(maxSum + 1, 0));

    // Base Case: 1 valid way to split an empty string
    for (int prevSum = 0; prevSum <= maxSum; prevSum++)
        dp[n][prevSum] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prevSum = 0; prevSum <= maxSum; prevSum++)
        {
            int currSum = 0;

            // Try all substrings starting at index i
            for (int j = i; j < n; j++)
            {
                currSum += s[i] - '0';

                // Only proceed if sum is valid
                if (currSum >= prevSum)
                    dp[i][prevSum] += dp[j + 1][currSum];
            }
        }
    }

    return dp[0][0];
}

int main()
{
    string s = "1119";

    cout << validGroups(s) << endl;

    return 0;
}