#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int cutRod(vector<int> &price)
{
    int n = price.size();

    // 1d dp[] to keep track of max profit values for every rod length
    vector<int> dp(n + 1, 0);

    // explore all the possible ways of cutting the rod in two pieces and
    // compute the max profit from all of the ways
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    // return the max profit value for cut of rod length 'n' in two pieces
    return dp[n];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}