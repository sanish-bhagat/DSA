#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int node, vector<bool> &vis)
{
    // base case: already visited node -> return
    if (vis[node])
        return;

    // mark the curr node as visited
    vis[node] = true;

    // recursively explore all the adjacent nodes of the curr, if not visited yet
    for (auto x : adj[node])
    {
        if (!vis[x])
            dfs(adj, x, vis);
    }
}

//! TC is O(v + e)
//! SC is O(v)

int makeConnected(int n, int connections[][2], int m)
{
    // track already visited nodes
    vector<bool> vis(n, false);

    // adjcacency matrix for undirected graph
    vector<vector<int>> adj(n);

    // track the no. of edges and components
    int edges = 0, components = 0;

    // build adjacency matrix
    for (int i = 0; i < m; i++)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);

        edges++;
    }

    // find the no. of components in the graph
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            components++;

            dfs(adj, i, vis);
        }
    }

    // cannot connect all nodes ->
    // since in a graph having 'n' nodes, the min no. of edges required is 'n-1' to make all the nodes connected
    if (edges < n - 1)
        return -1;

    // return the min no. of edges i.e (n-1) edges
    return components - 1;
}

int main()
{
    // Given number of computers
    int N = 4;

    // Given set of connections
    int connections[][2] = {{0, 1}, {0, 2}, {1, 2}};
    int M = sizeof(connections) / sizeof(connections[0]);

    // Function call to check if it is
    // possible to connect all computers or not
    cout << makeConnected(N, connections, M);

    return 0;
}