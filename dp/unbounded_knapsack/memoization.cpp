#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int i, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &memo)
{
    // all items have been traversed
    if (i == val.size())
        return 0;

    // already computed subproblem
    if (memo[i][capacity] != -1)
        return memo[i][capacity];

    // if including the current weight keeps the weight of the bag inside the capacity boundary ->
    // include it and recurse for the same item with update capacity(we can take the item multiple times)
    int take = 0;
    if (wt[i] <= capacity)
        take = val[i] + knapsackRec(i, capacity - wt[i], val, wt, memo);

    // exclude the curr item
    int notake = knapsackRec(i + 1, capacity, val, wt, memo);

    // pick the max profit value from both the cases
    return memo[i][capacity] = max(take, notake);
}

//! TC is O(n * capacity)
//! SC is O(n * capacity)

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // 2d memo[][] to keep track of the max profit values during traversal
    vector<vector<int>> memo(val.size() + 1, vector<int>(capacity + 1, -1));

    return knapsackRec(0, capacity, val, wt, memo);
}

int main()
{
    vector<int> val = {1, 1}, wt = {2, 1};
    int capacity = 3;
    cout << knapSack(capacity, val, wt);
}