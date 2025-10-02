#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    // build the adjacency matrix for the directed graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    return adj;
}

bool dfsCheck(int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
{
    // mark the node as visited and include it in the curr dfs path
    vis[src] = 1;
    pathVis[src] = 1;

    // visit the adjacent nodes
    for (int i : adj[src])
    {
        // recursive call for the adjacent node
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis))
                return true;
        }
        // the adjacent node is already included in the curr path
        // this means that the node has been visited twice and already in the dfs path, so it leads to a cycle
        else if (pathVis[i])
            return true;
    }

    // remove the node from the curr dfs path
    pathVis[src] = 0;
    return false;
}

//! TC is O(v + e)
//! SC is O(v)

bool isCyclic(int V, vector<vector<int>> &edges)
{
    // build the adjacency matrix
    vector<vector<int>> adj = buildAdj(V, edges);

    // visited[] -> to keep track of the visited elements
    // pathVis[] -> to keep track of the nodes in the curr recursion stack(curr dfs path)
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    // travserse the graph component wise(for disconnected graph)
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // dfs recursive check for cycle
            if (dfsCheck(i, adj, vis, pathVis))
                return true;
        }
    }

    return false;
}

int main()
{
    int V = 4; // Number of vertices

    // Directed edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};

    // Output whether the graph contains a cycle
    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}