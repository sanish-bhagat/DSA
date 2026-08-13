#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//! TC is O(v + e)
//! SC is O(v + e)

vector<int> maxDistance(int V, int src, vector<vector<int>> &edges)
{
    // Build the adjacency list and indegree array
    vector<vector<pair<int, int>>> g(V);
    vector<int> indegree(V, 0);

    for (auto &ed : edges)
    {
        int u = ed[0];
        int v = ed[1];
        int wt = ed[2];

        g[u].push_back({v, wt});
        indegree[v]++;
    }

    // Kahn's Algorithm to obtain a topological ordering
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topoOrder;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topoOrder.push_back(node);

        for (auto &it : g[node])
        {
            int v = it.first;

            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // Initialize all distances as unreachable
    vector<int> dist(V, INT_MIN);
    dist[src] = 0;

    // Process vertices in topological order and
    // relax outgoing edges to compute longest paths
    for (int node : topoOrder)
    {
        // Skip unreachable vertices
        if (dist[node] == INT_MIN)
            continue;

        for (auto &it : g[node])
        {
            int v = it.first;
            int wt = it.second;

            dist[v] = max(dist[v], dist[node] + wt);
        }
    }

    return dist;
}

int main()
{
    int V = 5, src = 1;

    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 2}, {1, 4, 4}, {3, 2, -1}, {4, 2, 3}, {4, 3, 6}};

    vector<int> ans = maxDistance(V, src, edges);

    cout << "[";

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == INT_MIN)
            cout << "INF";
        else
            cout << ans[i];

        if (i != ans.size() - 1)
            cout << ", ";
    }

    cout << "]";

    return 0;
}