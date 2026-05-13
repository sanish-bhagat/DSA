#include <bits/stdc++.h>
using namespace std;

// dfs traversal for graph
void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[node] = true;

    for (int neighbor : adj[node])
        if (!vis[neighbor])
            dfs(neighbor, vis, adj);
}

//! TC is O(V + E)
//! SC is O(V)

int findMotherVertex(int V, vector<vector<int>> &edges)
{
    // build the adjacency matrix for directed graph
    vector<vector<int>> adj(V);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
    }

    // keep track of visited nodes
    vector<bool> vis(V, false);

    int candidate = 0;

    // start dfs and find the last finished vertex
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj);

            // candidate mother vertex
            candidate = i;
        }
    }

    // check if candidate reaches all vertices
    fill(vis.begin(), vis.end(), false);
    dfs(candidate, vis, adj);

    // if any vertex is remained unvisited -> no mother vertex present
    for (bool v : vis)
        if (!v)
            return -1;

    // the candidate is the mother vertex
    return candidate;
}

int main()
{
    int V = 7;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {4, 1}, {6, 4}, {5, 6}, {5, 2}, {6, 0}};

    cout << findMotherVertex(V, edges) << endl;
    return 0;
}