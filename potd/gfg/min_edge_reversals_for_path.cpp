#include <bits/stdc++.h>
using namespace std;

//! TC is O(v + e)
//! SC is O(v + e)

int minimumEdgeReversal(vector<vector<int>> &edges, int src, int dst)
{
    int V = edges.size();

    // adjaceny matrix, 0 wt -> direct edge, 1 wt -> reversed edge
    vector<vector<pair<int, int>>> adj(V + 1);

    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], 0});
        adj[e[1]].push_back({e[0], 1});
    }

    // start from the src node
    deque<int> dq;
    vector<int> dist(V + 1, INT_MAX);

    dq.push_back(src);
    dist[src] = 0;

    while (dq.size() > 0)
    {
        // always pick the node from the front
        int u = dq.front();
        dq.pop_front();

        // visit the neighbors
        for (auto neighbors : adj[u])
        {
            int v = neighbors.first;
            int w = neighbors.second;

            // dijikstra idea -> take the min edge weight
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;

                // direct edge -> push into the front
                if (w == 0)
                    dq.push_front(v);

                // reversed edge -> push into the back
                else
                    dq.push_back(v);
            }
        }
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {3, 2}};
    int src = 1, dst = 3;

    cout << minimumEdgeReversal(edges, src, dst);
}