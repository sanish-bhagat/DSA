#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    // build adjancency matrix for undirected graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    return adj;
}

bool detectCycle(int src, vector<vector<int>> &adj, vector<int> &vis, int parent)
{
    // mark the curr vertex as visited
    vis[src] = 1;

    // visit the adjacent vertices from the curr node
    for (int i : adj[src])
    {
        // visit the vertex with the the new parent
        if (!vis[i])
        {
            if (detectCycle(i, adj, vis, src))
                return true;
        }
        // vertex already visited and its not a parent, then cycle is present
        else if (i != parent)
            return true;
    }

    return false;
}

//! TC is O(v + e)
//! SC is O(v + e)

bool isCycle(int V, vector<vector<int>> &edges)
{
    // build the adjacency matrix
    vector<vector<int>> adj = buildAdj(V, edges);

    // visited array to track the visited vertices
    vector<int> vis(V, 0);

    // traverse the graph component wise(for disconnected graph)
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // cycle detected
            if (detectCycle(i, adj, vis, -1))
                return true;
        }
    }

    return false;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {3, 4}};

    if (isCycle(V, edges))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}