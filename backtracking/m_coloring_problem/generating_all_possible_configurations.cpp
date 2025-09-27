#include <bits/stdc++.h>
using namespace std;

bool goodColor(vector<int> &color, vector<int> adj[])
{
    // check if the adjacent vertices have different colors or not
    for (int i = 0; i < color.size(); i++)
    {
        for (auto it : adj[i])
        {
            // different nodes and same color, then return false
            if (i != it && color[i] == color[it])
                return false;
        }
    }

    return true;
}

bool generateColor(int i, vector<int> &color, vector<int> adj[], int m)
{
    // if all colors are used
    if (i >= color.size())
    {
        // results to a solution, then return true
        if (goodColor(color, adj))
            return true;

        return false;
    }

    // recursively use different color, to find the solution
    for (int j = 0; j < m; j++)
    {
        // assign the color
        color[i] = j;

        // recursive call for other nodes
        if (generateColor(i + 1, color, adj, m))
            return true;

        // backtrack
        color[i] = -1;
    }

    return false;
}

//! TC is O((v + e) * m ^ v)
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

    return generateColor(0, color, adj, m);
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