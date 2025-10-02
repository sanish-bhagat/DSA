#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool detect(int src, vector<vector<int>> &adj, vector<int> &vis)
    {
        // mark current vertex as visited
        vis[src] = 1;

        // queue to keep track of current vertex and parent vertex
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            // pop the curr vertex and its parent vertex(i.e from where we started the bfs)
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // visit all its adj node
            for (auto adjNode : adj[node])
            {
                // mark curr node as visited and push the pair of adjNode and parent node into the queue
                if (!vis[adjNode])
                {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                // vertex already visited and its not a parent, then cycle is present
                else if (parent != adjNode)
                {
                    return true;
                }
            }
        }

        return false;
    }

    vector<vector<int>> buildAdj(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        // build the adj matrix for undirected graph
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return adj;
    }

    //! TC is O(v + e)
    //! SC is O(v + e)
    
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // build the adj matrix
        vector<vector<int>> adj = buildAdj(V, edges);

        // visited array to track visited vertices
        vector<int> vis(V, 0);

        // traverse the graph component wise(for disconnected graphs)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // cycle detected
                if (detect(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    int V = 5; // number of vertices
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // creates a cycle
    };

    if (sol.isCyclic(V, edges))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph does not contain cycle\n";

    return 0;
}