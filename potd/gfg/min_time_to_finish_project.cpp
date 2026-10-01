#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> &duration, vector<vector<int>> &adj, vector<int> &state, vector<int> &dp, bool &cycle)
{
    // cycle exists
    if (state[node] == 1)
    {
        cycle = true;
        return 0;
    }

    // already visited node
    if (state[node] == 2)
        return dp[node];

    // mark the curr node as visiting
    state[node] = 1;

    int maxTime = 0;

    // max time among dependent modules
    for (int next : adj[node])
        maxTime = max(maxTime, dfs(next, duration, adj, state, dp, cycle));

    state[node] = 2;

    // add the curr module's duration
    dp[node] = duration[node] + maxTime;

    return dp[node];
}

//! TC is O(n + m)
//! SC is O(n + m)

int minTime(vector<int> &duration, vector<vector<int>> &dependencies)
{
    int n = duration.size();

    vector<vector<int>> adj(n);

    // build the directed adjacency matrix
    for (auto it : dependencies)
        adj[it[0]].push_back(it[1]);

    // keep track of curr state of every node,
    // 0 -> not visited, 1 -> currently visiting, 2 -> alredy visited
    vector<int> state(n, 0);

    // store the calculated completed time
    vector<int> dp(n, 0);

    bool cycle = false;
    int res = 0;

    // dfs for every module
    for (int i = 0; i < n; i++)
        res = max(res, dfs(i, duration, adj, state, dp, cycle));

    // cycle is present -> project can be completed
    if (cycle)
        return -1;

    return res;
}

int main()
{
    vector<int> duration = {10, 20, 30, 10, 30, 20};

    vector<vector<int>> dependencies = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    cout << minTime(duration, dependencies) << endl;

    return 0;
}