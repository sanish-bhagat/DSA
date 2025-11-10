#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n)
{
    if (n == 0 || W == 0)
        return 0;

    int pick = 0;

    // two cases

    // either we include the curr item in the knapsack,
    // if including it does not lead to outer bound of bag weight capacity
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1);

    // either we exclude the item
    int notPick = knapsackRec(W, val, wt, n - 1);

    return max(pick, notPick);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    return knapsackRec(W, val, wt, n);
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}