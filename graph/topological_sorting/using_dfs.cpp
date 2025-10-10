#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    // build adjacency matrix for directed acyclic graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);    // directed edge
    }

    return adj;
}

void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj)
{
    // mark the curr vertex as visited
    vis[node] = true;

    // explore all the adjacent vertices of the curr node if not visited
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }

    // after returning from the dfs recursive call, push the node into the stack
    st.push(node);
}

//! TC is O(v + e)
//! SC is O(v)

vector<int> topologicalSort(int V, vector<vector<int>> &edges)
{
    // adjacency matrix for DAG(directed acyclic graph)
    vector<vector<int>> adj = constructAdj(V, edges);

    // vis[] to track visited vertices
    vector<bool> vis(V, false);

    // stack for topological sort
    stack<int> st;

    // iterate through all the vertices and perform dfs for the unvisited vertices
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, st, adj);
    }

    // store the vertices in ans as topological sorted[]
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{

    // Graph represented as an adjacency list
    int v = 6;
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

    vector<int> ans = topologicalSort(v, edges);

    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}