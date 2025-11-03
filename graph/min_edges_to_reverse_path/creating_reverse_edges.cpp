#include <bits/stdc++.h>
using namespace std;

//! TTC is O(m * logn)
//! SC is O(n + m)

int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    // adjacency matrix,
    // for directed edges assign weight as 0 and for the reversed edges assign weight as 1
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back({edge[1], 0});
        adj[edge[1]].push_back({edge[0], 1});
    }

    //? perform the dijkstra algo, to find the min weighted path as the min edges required =>

    // min heap{weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // dist to every node from source
    vector<int> dist(n + 1, INT_MAX);

    // start from source node
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        // pick the min edge weight node
        auto node = pq.top();
        pq.pop();

        int w1 = node.first;
        int u = node.second;

        // explore the neighbors
        for (auto nxt : adj[u])
        {
            int v = nxt.first;
            int w2 = nxt.second;

            // min edge weight compared to the previous one
            if (w1 + w2 < dist[v])
            {
                dist[v] = w1 + w2;
                pq.push({dist[v], v});
            }
        }
    }

    // return the min dist for the destination as
    // the minimum edges required to reverse the path from source to destination
    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {2, 3}, {6, 3}, {6, 4}, {4, 5}, {5, 1}};
    int n = 7, src = 0, dst = 6;
    cout << minimumEdgeReversal(edges, n, src, dst);
    return 0;
}