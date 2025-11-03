#include <bits/stdc++.h>
using namespace std;

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

    // dist to every node from source
    vector<int> dist(n + 1, INT_MAX);

    // deque for storing nodes
    deque<int> dq;

    // start from the source node
    dist[src] = 0;
    dq.push_back(src);

    while (dq.size() > 0)
    {
        // always pick the node from the front of the deque
        int u = dq.front();
        dq.pop_front();

        // explore all neighbors
        for (auto nxt : adj[u])
        {
            int v = nxt.first;
            int w = nxt.second;

            // dijsktra idea(pick the minimum edge weight)
            if (dist[u] + w < dist[v])
            {
                dist[v] = w + dist[u];

                // if node has weight 0 -> original edge, push into front of deque
                if (w == 0)
                    dq.push_front(v);

                // if node has weight 1 -> reversed edge, push into back of deque
                else
                    dq.push_back(v);
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