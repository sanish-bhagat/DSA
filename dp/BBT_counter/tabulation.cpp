#include <bits/stdc++.h>
using namespace std;

#define MOD 10000000

//! TC is O(h)
//! SC is O(h)

long long countBT(int h)
{
    // base case: for 0 and 1 node trees its always trivially balanced
    if (h == 0 || h == 1)
        return 1;

    // 1d dp[] to keep track of BBT count based on height
    vector<long long> dp(h + 1, 0);

    // intialise value for tree having 0 or 1 root node
    dp[0] = dp[1] = 1;

    // iteratively fill the dp table
    for (int i = 2; i <= h; i++)
    {
        // count of BBT for different subtrees of different heights
        long long x = dp[i - 1];
        long long y = dp[i - 2];

        // calculate the total no. of BBT
        dp[i] = (x * x + 2 * x * y) % MOD;
    }

    // return the total count
    return dp[h];
}

int main()
{
    int h = 2;
    cout << countBT(h);
}