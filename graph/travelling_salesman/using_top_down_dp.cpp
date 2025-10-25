#include <bits/stdc++.h>
using namespace std;

int totalCost(int mask, int curr, int n, vector<vector<int>> &cost, vector<vector<int>> &memo)
{
    // base case: all cities are visited, return the cost required to return to the starting city(0)
    if (mask == (1 << n) - 1)
        return cost[curr][0];

    // already computed subproblem -> return the already calculated cost
    if (memo[curr][mask] != -1)
        return memo[curr][mask];

    int ans = INT_MAX;

    // explore all cities that have not been visited yet
    for (int i = 0; i < n; i++)
    {

        // if city is not visited, visit it and update the mask
        if ((mask & (1 << i)) == 0)
        {
            ans = min(ans, cost[curr][i] + totalCost((mask | (1 << i)), i, n, cost, memo));
        }
    }

    // return the minCost calculated for this subproblem
    return memo[curr][mask] = ans;
}

//! TC is O(n * n * 2^n)
//! SC is O(n & 2^n)

int tsp(vector<vector<int>> &cost)
{
    int n = cost.size();

    // 2D memo matrix to keep track of already cimputed subproblems
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));

    // start from city 0 and calculate the minCost required
    return totalCost(1, 0, n, cost, memo);
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