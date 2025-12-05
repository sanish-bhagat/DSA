#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    // wd dp table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // traverse through every item
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= capacity; j++)
        {

            // if including the current weight keeps the weight of the bag inside the capacity boundary ->
            // include it and the value for the same item with update capacity(we can take the item multiple times)
            int take = 0;
            if (wt[i] <= j)
                take = val[i] + dp[i][j - wt[i]];

            // exclude the curr item
            int notake = dp[i + 1][j];

            // always pick the max value
            dp[i][j] = max(take, notake);
        }
    }

    // return the max profit value
    return dp[0][capacity];
}

int main()
{
    vector<int> val = {1, 1}, wt = {2, 1};
    int capacity = 3;
    cout << knapSack(capacity, val, wt);
}