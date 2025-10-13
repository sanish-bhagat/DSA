#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    // build the adjacency matrix for the undirected graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    return adj;
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &component)
{
    // mark the node as true
    vis[node] = true;

    // include the node in the curr connection
    component.push_back(node);

    // explore all the adjcaent nodes
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
            dfs(adjNode, adj, vis, component);
    }
}

//! TC is O(v + e)
//! SC is O(v)

vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
{
    // adjcancey matrix for undirected graph
    vector<vector<int>> adj = constructAdj(V, edges);

    // bool[] to track visited nodes
    vector<bool> vis(V, false);

    vector<vector<int>> res;

    // iteratively traverse all the vertices
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // store the nodes int the curr connection
            vector<int> component;

            dfs(i, adj, vis, component);

            // push the curr component connection into res
            res.push_back(component);
        }
    }

    return res;
}

int main()
{
    // Number of nodes in the graph
    int V = 5;

    // Edge list representing the undirected graph as vector of vectors
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    // Get all connected components using the countComponents function
    vector<vector<int>> res = getComponents(V, edges);

    for (const auto &comp : res)
    {

        for (int node : comp)
        {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}