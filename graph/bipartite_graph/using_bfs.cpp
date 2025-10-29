#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return adj;
}

//! TC is O(v + e)
//! SC is O(v)

bool isBipartite(int V, vector<vector<int>> &edges)
{
    // build adjacency matrix
    vector<vector<int>> adj = constructAdj(V, edges);

    // color[] used to track already colored nodes
    vector<int> color(V, -1);

    // queue for bfs traversal
    queue<int> q;

    // explore all the components
    for (int i = 0; i < V; i++)
    {
        // if node is uncolored
        if (color[i] == -1)
        {
            // assign first color to this node
            q.push(i);
            color[i] = 0;

            // start bfs with this node
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                // explore all the neighbors
                for (auto adjNode : adj[node])
                {
                    // uncolored node -> color this neighbor node with the opposite color
                    if (color[adjNode] == -1)
                    {
                        // color = (1 -> 0) || (0 -> 1)
                        color[adjNode] = 1 - color[node];
                        q.push(adjNode);
                    }
                    // neighbor have same color as the node -> not a bipartite graph
                    else if (color[adjNode] == color[node])
                        return false;
                }
            }
        }
    }

    // bfs completes without any conflict -> graph is a bipartite graph
    return true;
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    if (isBipartite(V, edges))
        cout << "true";
    else
        cout << "false";

    return 0;
}