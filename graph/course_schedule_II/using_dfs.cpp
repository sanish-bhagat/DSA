#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdj(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(n);

    // build the adjacency matrix(it[1] -> it[0])
    // for prerequistes[x, y] -> y should be done first if we want to take x
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    return adj;
}

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &st)
{
    // mark the node as currrently visiting
    vis[node] = 1;

    // explore all the adjacent nodes
    for (auto adjNode : adj[node])
    {
        // currently visiting -> leads to cycle
        if (vis[adjNode] == 1)
            return false;

        // node not visited
        else if (vis[adjNode] == 0)
        {
            // recursivly check for the adjacent node
            if (!dfs(adjNode, adj, vis, st))
                return false;
        }
    }

    // after returning from the recursive call, mark the node as visited
    vis[node] = 2;

    // store the node in st
    st.push_back(node);

    // return true -> valid order till now
    return true;
}

//! TC is O(v + e)
//! SC is O(v)

vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
{
    // adjcancey matrix for courses
    vector<vector<int>> adj = constructAdj(n, prerequisites);

    // track courses,
    // 0 -> not visited, 1 -> currently visiting, 2 -> already visited
    vector<int> vis(n, 0);

    // store the valid order
    vector<int> st;

    // iteratively traverse the courses
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // detects a cycle -> return {}
            if (!dfs(i, adj, vis, st))
                return {};
        }
    }

    // reverse the st[] to get the valid topological order
    reverse(st.begin(), st.end());
    return st;
}

int main()
{
    int n = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> order = findOrder(n, prerequisites);

    for (int course : order)
    {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}