#include <bits/stdc++.h>
using namespace std;

//! TC is O(V + E)
//! SC is O(V + E)

class Solution
{
public:
    bool ans = false;

    void solve(int node, int dest, vector<vector<int>> &adj, vector<bool> &vis)
    {
        // mark the curr node as visited
        vis[node] = true;

        // explore all the neighbors
        for (int neighbors : adj[node])
        {
            // reached the dest
            if (node == dest)
            {
                ans = true;
                return;
            }

            // explore all the unvisited neighbors
            if (!vis[neighbors])
                solve(neighbors, dest, adj, vis);
        }

        return;
    }

    bool checkPath(vector<vector<int>> &adj, int u, int v)
    {
        // boolean[] to keep track of visited nodes
        vector<bool> vis(adj.size(), false);

        // perform dfs
        solve(u, v, adj, vis);

        return ans;
    }
};

int main()
{
    vector<vector<int>> adj = {{2, 3}, {2}, {0, 1}, {0}, {5}, {4}};
    int u = 2, v = 3;

    Solution sol;

    cout << sol.checkPath(adj, u, v);
}