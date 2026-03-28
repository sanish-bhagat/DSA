#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &tin,
         vector<int> &low, vector<bool> &isArticulation, int &timer)
{
    // mark the curr node visited and set the time
    vis[node] = true;
    low[node] = tin[node] = timer++;

    int children = 0;

    // traverse through the neighbors
    for (int neighbor : adj[node])
    {

        if (!vis[neighbor])
        {

            dfs(neighbor, node, vis, adj, tin, low, isArticulation, timer);

            low[node] = min(low[node], low[neighbor]);

            // articulation condn
            if (low[neighbor] >= tin[node] && parent != -1)
                isArticulation[node] = true;

            children++;
        }

        // back edge
        else
            low[node] = min(low[node], tin[neighbor]);
    }

    // root case -> root has no parent and has more than 1 child -> articulation point
    if (parent == -1 && children > 1)
        isArticulation[node] = true;
}

//! TC is O(V + E)
//! SC is O(V + E)

vector<int> articulationPoints(int V, vector<vector<int>> &edges)
{
    // build the adj matrix for the undirected graph
    vector<vector<int>> adj(V);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // tin -> time when node is first visited
    // low -> lowest reachable time from that node (including back edges)
    vector<int> tin(V, -1), low(V, -1);

    vector<bool> vis(V, false);
    vector<bool> isArticulation(V, false);

    int timer = 0;

    // handles disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, -1, vis, adj, tin, low, isArticulation, timer);
    }

    // build the res[]
    vector<int> res;
    for (int i = 0; i < V; i++)
    {
        if (isArticulation[i])
            res.push_back(i);
    }

    if (res.empty())
        return {-1};

    return res;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};

    vector<int> res = articulationPoints(V, edges);

    for (int i : res)
        cout << i << " ";
}