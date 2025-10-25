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

void dfs(vector<vector<int>> &adj, int it, vector<bool> &vis)
{
    vis[it] = true;

    for (int i : adj[it])
    {
        if (!vis[i])
            dfs(adj, i, vis);
    }
}

//! TC is O(v * (v + e))
//! SC is O(v)

vector<int> articulationPoints(int V, vector<vector<int>> &edges)
{
    // construct adjacency matrix for the graph
    vector<vector<int>> adj = constructAdj(V, edges);

    vector<int> res;

    // iteratively traverse all the vertices and
    // check if i's neighbors kleads to more than one dfs call
    for (int i = 0; i < V; i++)
    {
        vector<bool> vis(V, false);
        vis[i] = true;

        // no. of dfs calls
        int comp = 0;

        // explore all the neighbors
        for (int it : adj[i])
        {

            // already lead to more than two different calls
            if (comp > 1)
                break;

            // dfs call for the connected graph
            if (!vis[it])
            {
                dfs(adj, it, vis);
                comp++;
            }
        }

        // more than one component, its an articulation point -> store it
        if (comp > 1)
            res.push_back(i);
    }

    if (res.empty())
        return {-1};

    return res;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    vector<int> ans = articulationPoints(V, edges);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}