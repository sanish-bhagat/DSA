#include <bits/stdc++.h>
using namespace std;

//! TC is O(v + e)
//! SC is O(v)

vector<int> bfs(vector<vector<int>> &adj)
{
    vector<int> res;

    // no of vertices
    int V = adj.size();

    // visited bool arr[]: to keep track of visited nodes, to avoid cycle
    vector<bool> visited(V, false);

    queue<int> q;

    // source node
    int s = 0;

    // mark the source node as visited and process the node
    visited[s] = true;
    q.push(s);

    // traverse the queue
    while (!q.empty())
    {
        // dequeue a vertex and store it in res
        int curr = q.front();
        q.pop();

        res.push_back(curr);

        // get the adjacent vertices of the curr dequeued vertex,
        // and mark it visited and push into queue, if not yet visited
        for (auto j : adj[curr])
        {
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }

    return res;
}

int main()
{

    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> ans = bfs(adj);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}