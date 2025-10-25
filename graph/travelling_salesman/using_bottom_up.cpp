#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * 2^n)
//! SC is O(n & 2^n)

int tsp(vector<vector<int>> &cost)
{
    int n = cost.size();
    if (n == 1)
        return cost[0][0]; // <-- handle n == 1

    int FULL = 1 << n;
    vector<vector<int>> dp(FULL, vector<int>(n, INT_MAX));
    dp[1][0] = 0; // start at city 0 with mask = 1

    for (int mask = 1; mask < FULL; ++mask)
    {
        for (int u = 0; u < n; ++u)
        {
            if (!(mask & (1 << u)))
                continue;
            if (dp[mask][u] == INT_MAX)
                continue;

            for (int v = 0; v < n; ++v)
            {
                if (mask & (1 << v))
                    continue;
                dp[mask | (1 << v)][v] = min(
                    dp[mask | (1 << v)][v],
                    dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; ++i)
        ans = min(ans, dp[FULL - 1][i] + cost[i][0]);

    return ans;
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