#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int col, vector<int> &color, vector<int> adj[])
{
    // check if the adjacent vertices have different colors or not
    for (auto it : adj[node])
    {
        if (color[it] != -1 && color[it] == col)
            return false;
    }

    return true;
}

bool canColor(int node, vector<int> &color, vector<int> adj[], int m)
{
    // all colors have been used
    if (node == color.size())
        return true;

    // recursively use different color, to find the solution
    for (int i = 0; i < m; i++)
    {
        // if assigning the curr color is safe, then do it
        if (isSafe(node, i, color, adj))
        {
            // assign color
            color[node] = i;

            // recursively check for other nodes
            if (canColor(node + 1, color, adj, m))
                return true;

            // backtrack
            color[node] = -1;
        }
    }

    return false;
}

//! TC is O(v * m^v)
//! SC is O(v + e)

bool graphColoring(int v, vector<vector<int>> &edges, int m)
{
    // prepare the adjacency matrix
    vector<int> adj[v];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // color[]: to keep track of the color which are already used
    vector<int> color(v, -1);

    return canColor(0, color, adj, m);
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    int m = 3;

    // Check if the graph can be colored with m colors
    // such that no adjacent nodes share the same color
    cout << (graphColoring(V, edges, m) ? "true" : "false") << endl;

    return 0;
}