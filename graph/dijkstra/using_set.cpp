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

    // set store unique values and store the minimum at the top,
    // and then stores all the values in ascending order
    set<pair<int, int>> st;

    // dist[]
    vector<int> dist(V, INT_MAX);

    st.insert({0, src});
    dist[src] = 0;

    while (!st.empty())
    {
        // min distance node in the set
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        // remove it from the set
        st.erase(it);

        // explore all the adjacent nodes
        for (auto x : adj[node])
        {
            int adjNode = x[0];
            int edgeWt = x[1];

            // founded the shorter dist than the previous one -> update
            if (dis + edgeWt < dist[adjNode])
            {

                // if node alreaady exists in set, remove it
                if (dist[adjNode] != INT_MAX)
                    st.erase({dist[adjNode], adjNode});

                // update the dist and insert the updated dist in the set
                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

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