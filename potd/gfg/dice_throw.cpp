#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m * x)
//! SC is O(x)

int noOfWays(int m, int n, int x)
{
    // 1d dp[] to store previous row values
    vector<int> dp(x + 1, 0);

    // there is 1 way to get sum = 0(using no dice)
    dp[0] = 1;

    // iterate through each dice from 1 to n
    for (int i = 1; i <= n; i++)
    {
        // iterate backwards through all the possible sums(j)
        // from x to i
        // to ensure that the results from previous states are not overwritten
        for (int j = x; j >= 1; j--)
        {
            // reset value of dp[j] before starting
            dp[j] = 0;

            // loop through all possible outcomes of the dice(k), from 1 to m(faces of the dice)
            // if j-k is a valid sum(non-negative), update dp[j]
            for (int k = 1; k <= m && j - k >= 0; k++)
                dp[j] += dp[j - k];
        }

        // reset, since there are no ways to get sum = 0
        dp[0] = 0;
    }

    // return the total no. of ways to get sum == x
    return dp[x];
}

int main()
{
    int m = 6, n = 3, x = 8;
    cout << noOfWays(m, n, x);
}