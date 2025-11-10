#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &memo)
{
    if (n == 0 || W == 0)
        return 0;

    // sub-problem already computed -> return the computed solution
    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;

    // two cases :-

    // either we include the curr item in the knapsack,
    // if including it does not lead to outer bound of bag weight capacity
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);

    // either we exclude the item
    int notPick = knapsackRec(W, val, wt, n - 1, memo);

    // include the max-one value 
    return memo[n][W] = max(pick, notPick);
}

//! TC is O(n * W)
//! SC is O(n * W)

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();

    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));

    return knapsackRec(W, val, wt, n, memo);
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}