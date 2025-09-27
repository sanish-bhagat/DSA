#include <bits/stdc++.h>
using namespace std;

// sort the items based on the profit/weight ratio
static bool compare(vector<int> &a, vector<int> &b)
{
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];

    return a1 > b1;
}

//! TC is O(n * logn)
//! SC is O(n)

int fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();

    // store the items along with its (profit, weight);
    vector<vector<int>> items(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }

    // sort them based on the profit / weight ratio in decreasing order
    sort(items.begin(), items.end(), compare);

    // track the ptrs
    double res = 0.0;
    int currentCapacity = capacity;

    // traverse the items[]
    for (int i = 0; i < n; i++)
    {
        // if entire current item can be put into the knapsack then do it
        if (items[i][1] <= currentCapacity)
        {
            res += items[i][0];
            currentCapacity -= items[i][1];
        }

        // if current capacity is less than the item's total weight then,
        // only put a fraction of the item into the knapsack
        else
        {
            res += (1.0 * items[i][0] / items[i][1]) * currentCapacity;
            break;
        }
    }

    // return the max value profit
    return res;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}