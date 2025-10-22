#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int node, int n, int count, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &path, vector<vector<int>> &allPaths)
    {
        // all nodes have been visited for once -> store the curr dfs path as an hamiltonian path
        if (count == n)
        {
            allPaths.push_back(path);
            return;
        }

        // explore all the neighbors
        for (auto adjNode : adj[node])
        {

            // visit the neighbor node if not been visited yet
            if (!vis[adjNode])
            {
                // include the neighbor node in curr dfs path
                vis[adjNode] = true;
                path.push_back(adjNode);

                // recursion for next neighbor node
                dfs(adjNode, n, count + 1, vis, adj, path, allPaths);

                // backtrack
                vis[adjNode] = false;
                path.pop_back();
            }
        }
    }

    //! TC is O(n!)
    //! SC is O(n + m)

public:
    vector<vector<int>> getAllHamiltonianPaths(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        // build the adjacency matrix
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // convert to 0-based indexing(if its 1-based)
            if (u >= n || v >= n)
            {
                u--;
                v--;
            }

            // link the edges
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> allPaths;

        // iteratively traverse every vertex and store the hamiltonian path, if exists
        for (int start = 0; start < n; start++)
        {
            // keep track of visited nodes
            vector<bool> vis(n, false);

            // curr recursive dfs path
            vector<int> path;

            // start the path from the curr source node(i.e, start)
            vis[start] = true;
            path.push_back(start);

            dfs(start, n, 1, vis, adj, path, allPaths);
        }

        return allPaths;
    }
};

int main()
{
    int n = 4, m = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};

    Solution sol;
    vector<vector<int>> paths = sol.getAllHamiltonianPaths(n, m, edges);

    cout << "All Hamiltonian Paths:\n";
    for (auto &p : paths)
    {
        for (int node : p)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}