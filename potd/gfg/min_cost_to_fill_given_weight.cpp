#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(int i, int w, vector<int> &cost, vector<vector<int>> &dp)
{
    // base case
    if (w == 0)
        return 0;

    // cannot fill the bag with the desired weight
    if (i == cost.size())
        return INF;

    // already computed subproblem
    if (dp[i][w] != -1)
        return dp[i][w];

    // take the curr orange weight till we can
    int take = INF;
    if (cost[i] != -1 && w >= (i + 1))
        take = cost[i] + solve(i, w - (i + 1), cost, dp);

    // skip the curr orange
    int noTake = solve(i + 1, w, cost, dp);

    // always take the min cost
    return dp[i][w] = min(take, noTake);
}

//! TC is O(n * w)
//! SC is O(n * w)

int minimumCost(vector<int> &cost, int w)
{
    int n = cost.size();

    // 2d dp table
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    // recurse to find the min cost
    int ans = solve(0, w, cost, dp);

    return ans >= INF ? -1 : ans;
}

int main()
{
    int w = 5;
    vector<int> cost = {20, 10, 4, 50, 100};
    cout << minimumCost(cost, w);
}