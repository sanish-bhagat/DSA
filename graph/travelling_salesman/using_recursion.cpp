#include <bits/stdc++.h>
using namespace std;

int tspRec(int mask, int pos, int n, vector<vector<int>> &cost)
{
    // base case: all cities are visited, return the cost required to return to the starting city(0)
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    int ans = INT_MAX;

    // try visiting very city that has not been visited yet
    for (int i = 0; i < n; i++)
    {

        // if city i is not visited, visit it and update the mask
        if ((mask & (1 << i)) == 0)
        {
            ans = min(ans, cost[pos][i] + tspRec(mask | (1 << i), i, n, cost));
        }
    }

    return ans;
}

//! TC is O(n!)
//! SC is O(n)

int tsp(vector<vector<int>> &cost)
{
    int n = cost.size();

    // recursive function to calculate the minCost
    return tspRec(1, 0, n, cost);
}

int main()
{

    vector<vector<int>> cost = {{0, 10, 15, 20},
                                {10, 0, 35, 25},
                                {15, 35, 0, 30},
                                {20, 25, 30, 0}};

    int res = tsp(cost);
    cout << res << endl;

    return 0;
}