#include <bits/stdc++.h>
using namespace std;

void generatePal(string &s, vector<vector<bool>> &isPal)
{
    int n = s.size();

    // 1length substring is always palindrome
    for (int i = 0; i < n; i++)
        isPal[i][i] = true;

    // check for every len substring
    for (int len = 2; len <= n; len++)
    {
        // traverse for substring of curr length
        for (int i = 0, j = i + len - 1; j < n; i++, j++)
        {
            // curr character matches and the rest of the suboart of string is a palindrome ->
            // curr substring is also a palindrome
            if (s[i] == s[j] && (len == 2 || isPal[i + 1][j - 1]))
                isPal[i][j] = true;
        }
    }
}

//! TC is O(n * n)
//! SC is O(n * n)

int palPartition(string &s)
{
    int n = s.size();

    // 2d[] -> tells wheter a substring is palindrome or not
    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    // find all the substring taht are palindrome
    generatePal(s, isPal);

    // 1d dp[] -> store the min cuts required for substring s[0...i]
    vector<int> dp(n, n);
    dp[0] = 0;

    // iterate through the string
    for (int i = 1; i < n; i++)
    {
        // substring is palindrome -> no cuts required
        if (isPal[0][i] == true)
            dp[i] = 0;

        else
        {
            // try for all the substring starting from j and ending at i
            for (int j = i; j >= 1; j--)
            {
                // substring is palindrome -> find the min cut required for palindrome partitioning
                if (isPal[j][i])
                    dp[i] = min(dp[i], 1 + dp[j - 1]);
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    string s = "geek";

    cout << palPartition(s) << endl;
    return 0;
}