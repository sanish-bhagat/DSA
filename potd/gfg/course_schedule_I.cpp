#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &visited)
{
    // mark the curr node as currrently visiting
    visited[node] = 1;

    // traverse through every neighbors of curr node
    for (int neighbor : adj[node])
    {
        // neighbor is already in curr path visiting state -> cycle exists
        if (visited[neighbor] == 1)
            return false;

        // perform dfs on the neighbor node
        else if (visited[neighbor] == 0)
        {
            if (!dfs(neighbor, adj, visited))
                return false;
        }
    }

    // mark the node as visited
    visited[node] = 2;
    return true;
}

//! TC is O(V + E)
//! SC is O(V + E)

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    // build the adjanceny matrix, {course -> prerequisite course}
    vector<vector<int>> adj(n);
    for (auto pre : prerequisites)
    {
        int dest = pre[0], src = pre[1];

        adj[src].push_back(dest);
    }

    // keep track of the curr state of the nodes,
    // 0 -> not visited, 1 -> visiting, 2 -> visited
    vector<int> visited(n, 0);

    // traverse through every course and perform dfs
    // cycle exists -> not able to finish all courses
    // cycle not exists -> possible to complete all courses
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == 0)
        {
            // cycle exists -> will not be able to finish all courses
            if (!dfs(i, adj, visited))
                return false;
        }
    }

    return true;
}

int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{2, 0}, {2, 1}, {3, 2}};

    cout << (canFinish(n, prerequisites) ? "true" : "false") << endl;

    return 0;
}