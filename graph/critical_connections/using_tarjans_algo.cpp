#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<bool> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges)
{
    // mark the node as visited
    vis[node] = true;

    // set the time values
    tin[node] = low[node] = timer;
    timer++;

    // explore all the neigbors
    for (int it : adj[node])
    {
        // skip if the neigbor during dfs traversal, is the parent
        if (it == parent)
            continue;

        if (!vis[it])
        {
            // dfs traversal for neigbor
            dfs(it, node, vis, adj, tin, low, bridges);

            // update the low value
            low[node] = min(low[node], low[it]);

            // bridge exists, since we cannot visit the node from 'it' via any backedge
            if (low[it] > tin[node])
                bridges.push_back({node, it});
        }
        else
        {
            // only update the low timer
            low[node] = min(low[node], low[it]);
        }
    }
}

//! TC is O(v + e)
//! SC is O(v + e)

vector<vector<int>> criticalConnections(int v, vector<int> adj[])
{
    // track visited nodes
    vector<bool> vis(v, false);

    // track the time of insertion of node(when we first visit the node)
    vector<int> tin(v);

    // the earliest vertex that can be reached from this node or its subtree
    vector<int> low(v);

    vector<vector<int>> bridges;

    // dfs traversal
    dfs(0, -1, vis, adj, tin, low, bridges);

    return bridges;
}

int main()
{
    int v = 3, e = 2;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans = criticalConnections(v, adj);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}