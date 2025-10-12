#include <bits/stdc++.h>
using namespace std;

// build the adjacency matrix for the courses
vector<vector<int>> constructAdj(int n, vector<pair<int, int>> &prerequisites)
{
    vector<vector<int>> adj(n);

    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    return adj;
}

bool dfs_cycle(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &onPath)
{
    // if already vis -> return false, no cycle
    if (vis[node])
        return false;

    // mark the curr course as visited and include it in the curr dfs path
    vis[node] = onPath[node] = true;

    // explore all the adjacent courses
    for (auto adjNode : adj[node])
    {
        // if curr adjacent course is in curr dfs path or it leads to any cycle -> return true, cycle detected
        if (onPath[adjNode] || dfs_cycle(adjNode, adj, vis, onPath))
            return true;
    }

    // exclude the curr course from the dfs path
    return onPath[node] = false;
}

//! TC is O(v + e)
//! SC is O(v)

bool canFinish(int n, vector<pair<int, int>> &prerequisites)
{
    // build the adjacency matrix for the courses
    vector<vector<int>> adj = constructAdj(n, prerequisites);

    // bool[], vis[] -> used for tracking visited courses and onPath -> track courses in curr dfs path
    vector<bool> vis(n, false), onPath(n, false);

    // iteratively traverse all the courses
    for (int i = 0; i < n; i++)
    {
        // if not visited and any cycle is detected, it means the prerequisites is not fulfilled -> return false
        if (!vis[i] && dfs_cycle(i, adj, vis, onPath))
            return false;
    }

    return true;
}

int main()
{
    int numTasks = 4;
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites))
    {
        cout << "Possible to finish all tasks";
    }
    else
    {
        cout << "Impossible to finish all tasks";
    }

    return 0;
}