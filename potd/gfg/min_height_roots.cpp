#include <bits/stdc++.h>
using namespace std;

//! TC is O(V)
//! SC is O(V)

vector<int> findMinHeight(int V, vector<vector<int>> &edges)
{
    // base case: less then two nodes
    if (V < 2)
    {
        vector<int> res;
        for (int i = 0; i < V; i++)
            res.push_back(i);

        return res;
    }

    // build the adjacency matrix for the undirected graph
    vector<vector<int>> adj(V);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // store the degree of every node
    vector<int> deg(V);
    for (int i = 0; i < V; i++)
        deg[i] = adj[i].size();

    // intialise the queue with the initially leaf nodes
    queue<int> leaves;
    for (int i = 0; i < V; i++)
        if (deg[i] == 1)
            leaves.push(i);

    int remNodes = V;

    // keep trimming the leaves level by level until we reach the centroids
    while (remNodes > 2)
    {
        int leafNodes = leaves.size();
        remNodes -= leafNodes;

        // remove leaf nodes from the curr level
        for (int i = 0; i < leafNodes; i++)
        {
            int leaf = leaves.front();
            leaves.pop();

            for (int neighbor : adj[leaf])
            {
                // decrement the degree of the neighbor
                deg[neighbor]--;

                // keep adding more leaf nodes
                if (deg[neighbor] == 1)
                    leaves.push(neighbor);
            }

            // remove the leaf node
            deg[leaf] = 0;
        }
    }

    // build the res[] with the remaining nodes(centroids)
    vector<int> res;
    while (!leaves.empty())
    {
        res.push_back(leaves.front());
        leaves.pop();
    }

    return res;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {2, 3}, {3, 4}};

    vector<int> result = findMinHeight(V, edges);

    for (int r : result)
        cout << r << " ";
    cout << endl;

    return 0;
}