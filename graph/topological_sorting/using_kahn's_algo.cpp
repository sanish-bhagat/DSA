#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    // build adjacency matrix for directed acyclic graph
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]); // directed edge
    }

    return adj;
}

//! TC is O(v + e)
//! SC is O(v)

vector<int> topologicalSort(int V, vector<vector<int>> &edges)
{
    // adjacency matrix for DAG(directed acyclic graph)
    vector<vector<int>> adj = constructAdj(V, edges);

    // compute the indegree of the vertices
    vector<int> inDegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            inDegree[it]++;
    }

    // push the vertex that have 0 indegree
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // bfs traversal
    vector<int> ans;
    while (!q.empty())
    {
        // pop the node having 0 indegree
        int node = q.front();
        q.pop();

        // store the vertex in the ans[]
        ans.push_back(node);

        // explore all the adjacent nodes
        for (auto it : adj[node])
        {
            // decreament the indegree of the adjacent vertex
            inDegree[it]--;

            // if indegree of the vertex becomes 0 then push it into the queue
            if (inDegree[it] == 0)
                q.push(it);
        }
    }

    // return the topological sorted[]
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