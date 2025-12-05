#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * W)
//! SC is O(n * W)

int MinimumCost(int cost[], int n, int W)
{
    // 1d[] used to keep track of the cost and weight for a particular item
    vector<int> val, wt;

    int size = 0;

    // include items which are available, i.e item having cost != -1
    for (int i = 0; i < n; i++)
    {
        if (cost[i] != -1)
        {
            val.push_back(cost[i]);
            wt.push_back(i + 1);
            size++;
        }
    }

    // available no. of distinct weighted packets
    n = size;

    int minCost[n + 1][W + 1];

    // fill 0th row with INF -> invalid cost as no item is included
    for (int i = 0; i <= W; i++)
        minCost[0][i] = INT_MAX;

    // fill 0th column with INF -> cost for every item having 0 weight = 0
    for (int i = 1; i <= n; i++)
        minCost[i][0] = 0;

    // fill the mincost matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // capacity of bag is less than the weight of th curr item
            if (wt[i - 1] > j)
                minCost[i][j] = minCost[i - 1][j];

            // get the min cost by either excluding or including the curr item
            else
                minCost[i][j] = min(minCost[i - 1][j], val[i - 1] + minCost[i][j - wt[i - 1]]);
        }
    }

    // return the min cost for W weight item included
    return (minCost[n][W] == INT_MAX) ? -1 : minCost[n][W];
}

int main()
{
    int cost[] = {1, 2, 3, 4, 5}, W = 5;
    int n = sizeof(cost) / sizeof(cost[0]);

    cout << MinimumCost(cost, n, W);
    return 0;
}