#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges, int c, int d)
{
    vector<vector<int>> adj(V);

    for (auto edge : edges)
    {
        // exclude the c -> d || d -> c edge
        if ((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c))
            continue;

        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return adj;
}

void dfs(vector<vector<int>> &adj, int c, vector<bool> &vis)
{
    vis[c] = true;

    // start the dfs traversal and explore all its neighbors
    for (int i : adj[c])
    {
        if (!vis[i])
            dfs(adj, i, vis);
    }
}

bool isBridge(int V, vector<vector<int>> &edges, int c, int d)
{
    // construct adj matrix excluding the edge(c -> d || d -> c)
    vector<vector<int>> adj = constructAdj(V, edges, c, d);

    vector<bool> vis(V, false);

    // start the dfs from any one of the vertex
    dfs(adj, c, vis);

    // if another node is not visited after dfs traversal -> graph is disconnected
    return !vis[d];
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    int c = 1, d = 2;
    cout << (isBridge(V, edges, c, d) ? "true" : "false") << endl;

    return 0;
}