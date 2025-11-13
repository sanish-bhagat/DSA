#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countFriendsPairings(int n)
{
    // 1D[] to store count for every ith combination friends
    int dp[n + 1];

    for (int i = 0; i <= n; i++)
    {
        // base case => f(0) = 0 -> empty set, no combination options possible
        // f(1) = 1 -> only single option
        // f(2) = 2 -> either both single or one pair option
        if (i <= 2)
            dp[i] = i;

        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n = 4;
    cout << countFriendsPairings(n) << endl;
    return 0;
}