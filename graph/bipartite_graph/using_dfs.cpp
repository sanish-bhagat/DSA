#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return adj;
}

bool dfs(int node, int color, vector<int> &colors, vector<vector<int>> &adj)
{
    // assign color to the curr node
    colors[node] = color;

    // explore all the neighbors
    for (auto adjNode : adj[node])
    {
        // neighbor not colored -> color it with opposite color
        if (colors[adjNode] == -1)
        {
            // perform dfs with opposite color
            if (!dfs(adjNode, 1 - color, colors, adj))
                return false;
        }

        // neighbor have same color as the node -> not a bipartite graph
        else if (colors[adjNode] == color)
            return false;
    }

    return true;
}

//! TC is O(v + e)
//! SC is O(v)

bool isBipartite(int V, vector<vector<int>> &edges)
{
    // adjacency matrix
    vector<vector<int>> adj = constructAdj(V, edges);

    // color[] used to track already colored nodes
    vector<int> colors(V, -1);

    // explore all the components
    for (int i = 0; i < V; i++)
    {
        // if node is not colored yet -> perform dfs(coloring with first color)
        if (colors[i] == -1)
        {
            if (!dfs(i, 0, colors, adj))
                return false;
        }
    }

    // return true if all vertices are colored bipartitely
    return true;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if (isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";

    return 0;
}