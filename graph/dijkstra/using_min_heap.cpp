#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> adj(V);

    for (auto edge : edges)
    {
        // fetch the src node, neighbor node and edge weight
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // store the links for undirected graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return adj;
}

//! TC is O(e * logv)
//! SC is O(v)

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    // adjacency matrix -> storing {neighbor node, edge weight}
    vector<vector<vector<int>>> adj = constructAdj(V, edges);

    // min heap -> {dist, node}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src});

    // distance[]
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    while (!pq.empty())
    {
        // min distance in the heap
        int dis = pq.top()[0];
        int node = pq.top()[1];

        pq.pop();

        // explore all the adjacent nodes
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            // founded the shorter dist than the previous one -> update
            if (dis + edgeWt < dist[adjNode])
            {
                // update the dist
                dist[adjNode] = dis + edgeWt;
                // push the update dist and node in the min-heap
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // return the shortest dist[]
    return dist;
}

int main()
{
    int V = 5;
    int src = 0;

    // edge list format: {u, v, weight}
    vector<vector<int>> edges = {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};

    vector<int> result = dijkstra(V, edges, src);

    // Print shortest distances in one line
    for (int dist : result)
        cout << dist << " ";

    return 0;
}