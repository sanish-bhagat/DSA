#include<bits/stdc++.h>
using namespace std;

void dfsRec(vector<vector<int>> &adj, int source, vector<bool> &visited, vector<int> &res) {
    // mark the curr vertex as visited
    visited[source] = 1;

    // push the visited vertex in the res[]
    res.push_back(source);

    // recursively traverse the adjacent vertices that are not visited yet
    for(auto i: adj[source]) {
        if(!visited[i])
            dfsRec(adj, i, visited, res);
    }
}

//! TC is O(v + e)
//! SC is O(v + e)

vector<int> dfs(vector<vector<int>> &adj) {
    int V = adj.size();

    // to track visited vertices
    vector<bool> visited(V, 0);

    vector<int> res;

    // source vertex
    int source = 0;

    // recursive func for dfs traversal
    dfsRec(adj, source, visited, res);

    return res;
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Add edges
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Starting vertex for DFS
    vector<int> res = dfs(adj); // Perform DFS starting from the source verte 0;

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
}