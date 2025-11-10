#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * W)
//! SC is O(W)

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    // 1D dp[]
    vector<int> dp(W + 1);

    // take first i elements
    for (int i = 1; i <= n; i++)
    {
        // starting from back, so that we also have data of the previous computations of i-1 items
        for (int j = W; j >= wt[i - 1]; j--)

            // pick the max-one in terms of value
            dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
    }

    return dp[W];
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}