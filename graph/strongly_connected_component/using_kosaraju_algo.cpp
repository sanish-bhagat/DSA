#include <bits/stdc++.h>
using namespace std;

class GFG
{
    // build the adjacency matrix(0-based)
    vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (auto edge : edges)
        {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }

        return adj;
    }

    // perform dfs traversal on orginal graph
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = true;

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, adj, st);
        }

        // store the nodes in decreasing order of finish time
        st.push(node);
    }

    // perform dfs traversal to count the no. of scc and store the scc subgraph
    void dfs3(int node, vector<bool> &vis, vector<vector<int>> &adjT, vector<int> &component)
    {
        vis[node] = true;
        component.push_back(node + 1);

        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT, component);
            }
        }
    }

public:
    //! TC is O(v + e)
    //! Sc is O(v + e)

    vector<vector<int>> findSCC(int V, vector<vector<int>> &edges)
    {
        // construct the adjacency matrix(i -> it)
        vector<vector<int>> adj = constructAdj(V, edges);

        // track visited nodes
        vector<bool> vis(V, false);

        // stack used for sorting the nodes based on the decreasing order of the finish time ofnodes(time at which the dfs finishes exploring a node completely)
        stack<int> st;

        // perforom dfs on the original graph and record the finish time
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, vis, adj, st);
        }

        // reverse all the edges of the graph(it -> i)
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = false;

            for (auto it : adj[i])
                adjT[it].push_back(i);
        }

        vector<vector<int>> res;

        // perform dfs on the transpsed graph based on the decreasing order of finish time
        while (!st.empty())
        {
            int it = st.top();
            st.pop();

            if (!vis[it])
            {
                // store the curr subgraph
                vector<int> component;
                dfs3(it, vis, adjT, component);
                res.push_back(component);
            }
        }

        return res;
    }
};

int main()
{

    GFG obj;
    int V = 5;
    vector<vector<int>> edges{
        {1, 3}, {1, 4}, {2, 1}, {3, 2}, {4, 5}};
    vector<vector<int>> ans = obj.findSCC(V, edges);
    cout << "Strongly Connected Components are:\n";
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}