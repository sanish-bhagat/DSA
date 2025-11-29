#include <bits/stdc++.h>
using namespace std;

int helper(int n, int k, vector<vector<int>> &memo)
{
    // already computed subproblem
    if (memo[n][k] != -1)
        return memo[n][k];

    // base case: less than or equal to one floor
    if (k == 1 || k == 0)
        return k;

    // base case: only one egg left
    if (n == 1)
        return k;

    int res = INT_MAX;

    // iterate through every floor, consider dropping for every floor from 1 to k
    for (int i = 1; i <= k; i++)
    {
        // pick the max b/w
        // 1. either egg breaked from the curr floor, move to  the lower floor with one less egg
        // 2.  or egg does not broke then move to the higher floors with the same no. of eggs
        int curr = 1 + max(helper(n - 1, i - 1, memo), helper(n, k - i, memo));

        // pick the min of the max ones
        if (curr < res)
            res = curr;
    }

    return memo[n][k] = res;
}

//! TC is O(n * k)
//! SC is O(n * k)

int eggDrop(int n, int k)
{
    // 2d memo[] to keep track of computation during recursive calls
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    return helper(n, k, memo);
}

int main()
{
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}