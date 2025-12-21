#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool findWinner(int x, int y, int n)
{
    // 1d dp[] to store possible winner for every value of coin i from (0...n)
    int dp[n + 1];

    // initialise value
    dp[0] = false;
    dp[1] = true;

    // compute value for every i
    for (int i = 2; i <= n; i++)
    {
        // if A losses any of the i-1 or i-x or i-y game then he will definitely win game i
        if (i - 1 >= 0 && !dp[i - 1])
            dp[i] = true;

        else if (i - x >= 0 && !dp[i - x])
            dp[i] = true;

        else if (i - y >= 0 && !dp[i - y])
            dp[i] = true;

        // else A losses the game
        else
            dp[i] = false;
    }

    // dp[n] = true -> A wins the game, else if dp[n] = false -> A losses the game
    return dp[n];
}

int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}