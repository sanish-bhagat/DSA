#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> adj(V);

    // build the weighted adjacency matrix
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return adj;
}

//! TC is O((e + v) * logv)
//! SC is O(e + v)

int spanningTree(int V, vector<vector<int>> &edges)
{
    // adjacency for the weighted undirected graph
    vector<vector<vector<int>>> adj = constructAdj(V, edges);

    // keep track of visited vertices, to avoid cycle
    vector<bool> vis(V, false);

    // min heap {wt, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // start from the first node
    pq.push({0, 0});

    int res = 0;

    while (!pq.empty())
    {
        // pick the min edge weight vertex
        auto p = pq.top();
        pq.pop();

        int u = p.second;
        int w = p.first;

        // already visited -> including it may lead to cycle
        if (vis[u])
            continue;

        // include in the MST
        vis[u] = true;
        res += w;

        // explore all the adjacent nodes
        for (auto v : adj[u])
        {
            int adjNode = v[0];
            int edgeWt = v[1];

            if (!vis[adjNode])
                pq.push({edgeWt, adjNode});
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 5},
                                 {1, 2, 3},
                                 {0, 2, 1}};

    cout << spanningTree(3, graph) << endl;

    return 0;
}