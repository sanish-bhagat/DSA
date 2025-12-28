#include <bits/stdc++.h>
using namespace std;

//! TC is O(n ^ 3)
//! SC is O(n * n)

int palPartition(string &s)
{
    int n = s.size();

    // 2d dp[] -> stores the min cuts for the palindrome partioning for  every substring
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 2d isPal[] -> tells whether the substring is palindrome or not
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // substring of 1length is always a palindrome -> therefor no cuts required
    for (int i = 0; i < n; i++)
    {
        isPal[i][i] = true;
        dp[i][i] = 0;
    }

    // iteratively try for every len of substring
    for (int len = 2; len <= n; len++)
    {
        // compute the values for substring of the curr len
        for (int i = 0, j = i + len - 1; j < n; i++, j++)
        {
            // substring len is 2, therefor we need to check for only two characters for palindrome
            if (len == 2)
                isPal[i][j] = (s[i] == s[j]);

            // else we check the curr two character and for isPal[i + 1][j - 1]
            else
                isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];

            // substring is palindrome -> no cuts required
            if (isPal[i][j] == true)
                dp[i][j] = 0;

            // try all possible partitions and pick the min cut required
            else
            {
                dp[i][j] = INT_MAX;

                // try all positions for partiton
                for (int k = i; k < j; k++)
                {
                    // pick the min cuts needed
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    // return the min cuts required for palindrome partitioning for the given string
    return dp[0][n - 1];
}

int main()
{
    string s = "geek";

    cout << palPartition(s) << endl;
    return 0;
}