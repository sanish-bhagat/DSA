#include <bits/stdc++.h>
using namespace std;

int knapsackRec(int i, int capacity, vector<int> &val, vector<int> &wt)
{
    // traversed all the items
    if (i == val.size())
        return 0;

    // if including the current weight keeps the weight of the bag inside the capacity boundary ->
    // include it and recurse for the same item with update capacity(we can take the item multiple times)
    int take = 0;
    if (wt[i] <= capacity)
        take = val[i] + knapsackRec(i, capacity - wt[i], val, wt);

    // exclude the curr item
    int notake = knapsackRec(i + 1, capacity, val, wt);

    // pick the max profit value from both the cases
    return max(take, notake);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int knapSack(int capacity, vector<int> &val, vector<int> &wt)
{
    // recurse from the 0th item
    return knapsackRec(0, capacity, val, wt);
}

int main()
{
    vector<int> val = {1, 1}, wt = {2, 1};
    int capacity = 3;
    cout << knapSack(capacity, val, wt);
}