#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;

    for (int nei : adj[node])
    {
        if (!vis[nei])
        {
            dfs(nei, adj, vis);
        }
    }
}

//! TC is O(n + m)
//! SC is O(n + m)

int minEdgesReq(int n, vector<vector<int>> &edges)
{
    // A connected graph with n vertices requires
    // at least (n - 1) edges
    if ((int)edges.size() < n - 1)
    {
        return -1;
    }

    // Build adjacency list
    vector<vector<int>> adj(n);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    int components = 0;

    // Count connected components using DFS.
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            components++;
            dfs(i, adj, vis);
        }
    }

    // To connect 'components' disconnected parts,
    // we need exactly (components - 1) operations
    return components - 1;
}

int main()
{
    int n = 4;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2}};

    cout << minEdgesReq(n, edges) << "\n";

    return 0;
}