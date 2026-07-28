#include <bits/stdc++.h>
using namespace std;

//! TC is O(v + e)
//! SC is O(v + e)

int shortestPath(int V, int src, int dest, vector<vector<int>> &edges)
{
    int extra = V;

    // Create adjacency list. Extra nodes
    // are used to split weight 2 edges.
    vector<vector<int>> adj(V + edges.size());

    for (auto e : edges)
    {
        int u = e[0], v = e[1], w = e[2];

        // Weight 1 edge remains unchanged.
        if (w == 1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        else
        {
            // Convert weight 2 edge into two weight 1 edges:
            // u -- 1 -- newNode -- 1 -- v
            adj[u].push_back(extra);
            adj[extra].push_back(u);

            adj[v].push_back(extra);
            adj[extra].push_back(v);

            extra++;
        }
    }

    vector<int> dist(extra, -1);

    // BFS on the transformed unweighted
    // graph gives shortest distance.
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == dest)
            return dist[node];

        // visit all the neighbors
        for (int nxt : adj[node])
        {
            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[node] + 1;
                q.push(nxt);
            }
        }
    }

    // dest cannot be reached from src node
    return -1;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 2}, {2, 3, 1}, {1, 2, 1}, {1, 3, 2}};
    int src = 0, dest = 3;
    cout << shortestPath(V, src, dest, edges) << endl;

    return 0;
}