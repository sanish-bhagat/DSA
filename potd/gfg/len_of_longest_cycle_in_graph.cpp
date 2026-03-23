#include <bits/stdc++.h>
using namespace std;

//! TC is O(V)
//! SC is O(V)

int longestCycle(int V, vector<vector<int>> &edges)
{
    // build the adjacency matrix
    vector<int> adj(V, -1);
    for (auto e : edges)
        adj[e[0]] = e[1];

    // keep track of the visited nodes
    vector<bool> visited(V, 0);

    int maxLen = -1;

    // traverse through every vertex
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            continue;

        int node = i;
        int step = 0;

        // stores step no. of node in curr path
        unordered_map<int, int> stepMap;

        // traverse through the curr path
        while (node != -1 && !visited[node])
        {
            // include the curr node in the path -> mark it visited
            visited[node] = 1;
            stepMap[node] = step++;

            // move to next vertex
            node = adj[node];

            // node already present in the stepmap -> cycle exists
            if (node != -1 && stepMap.count(node))
            {
                int currLen = step - stepMap[node];
                maxLen = max(maxLen, currLen);
            }
        }
    }

    return maxLen;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};

    cout << longestCycle(V, edges);
}