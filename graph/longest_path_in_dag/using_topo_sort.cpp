#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void topoSort(int node, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st)
    {
        // mark the node as visited
        vis[node] = true;

        // explore all the unvisited nodes
        for (auto it : adj[node])
        {
            int v = it.first;

            if (!vis[v])
                topoSort(v, adj, vis, st);
        }

        // push node in toposort order
        st.push(node);
    }

public:

    //! TC is O(v + e)
    //! SC is O(v + e)
    vector<int> longestPath(int V, int E, vector<vector<int>> &edges, int src)
    {
        // build the adjacency matrix for DAG
        vector<pair<int, int>> adj[V];
        for (auto edge : edges)
            adj[edge[0]].push_back({edge[1], edge[2]});

        // stack for toposort
        stack<int> st;
        vector<bool> vis(V, false);

        // find the toposort of the dag
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        vector<int> dist(V, INT_MIN);

        // mark distance for source node as 0
        dist[src] = 0;

        // use the toposort and maximise the distance
        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            // only process if the node is reachable
            if(dist[u] != INT_MIN) {
                // explore all the neighbors
                for (auto it : adj[u])
                {
                    int v = it.first;
                    int w = it.second;

                    // maximise distance
                    if (dist[v] < dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }
        }

        return dist;
    }
};

int main()
{
    int V = 6, E = 7;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 3, 6},
        {1, 2, 2},
        {2, 4, 4},
        {2, 5, 2},
        {4, 5, 1}};
    int source = 1;

    Solution obj;
    vector<int> result = obj.longestPath(V, E, edges, source);

    cout << "Longest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        if (result[i] == INT_MIN)
            cout << "INF ";
        else
            cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}