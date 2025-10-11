#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
    vector<vector<pair<int, int>>> constructAdj(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        return adj;
    }

    // find the topological Sorting
    void topoSort(int node, vector<bool> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &st)
    {
        vis[node] = true;

        for (auto it : adj[node])
        {
            int adjNode = it.first;

            if (!vis[adjNode])
                topoSort(adjNode, vis, adj, st);
        }

        st.push(node);
    }

public:
    //! TC is O(v + e)
    //! SC is O(v)

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // adjacency matrix for DAG
        vector<vector<pair<int, int>>> adj = constructAdj(V, edges);

        // stack for storing topo sort
        stack<int> st;

        // bool[] to track visited vertices
        vector<bool> vis(V, false);

        // build the topo sort
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topoSort(i, vis, adj, st);
        }

        // dist[]
        vector<int> dist(V, INT_MAX);

        // dist for source node is 0(here source vertex is 0)
        dist[0] = 0;

        // calculate the shortest dist[] using the toposort
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX)
            {
                // explore the adjcaent nodes of the vertex
                for (auto it : adj[node])
                {
                    // curr adjnode and edge weight
                    int adjNode = it.first;
                    int wt = it.second;

                    // found a shortest dist
                    if (dist[node] + wt < dist[adjNode])
                        dist[adjNode] = dist[node] + wt;
                }
            }
        }

        // replace INT_MAX with -1 in the final dist[]
        for (int &i : dist)
        {
            if (i == INT_MAX)
                i = -1;
        }

        return dist;
    }
};

int main()
{
    int V = 6;
    int E = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};

    Solution obj;
    vector<int> result = obj.shortestPath(V, E, edges);

    cout << "Shortest distances from source node 0:\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;
}