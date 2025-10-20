#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n)

bool isNegativeWeightCycle(int n, vector<vector<int>> &edges)
{
    // shortest dist[]
    vector<int> dist(n, INT_MAX);

    // for disconnected graph -> initialise distance[] with 0

    // dist for source node
    dist[0] = 0;

    // relax the edges for (n - 1) times -> to get the shortest dist[]
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            // found a shortest dist than the previous itertaion
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // detect -ve cycle ->
    // if after (n - 1) iterations, we are still able to relax(update dist[]), then we have detected a cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return true;
    }

    // no -ve cycle detected
    return false;
}

int main()
{
    int n = 5, m = 8;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    if (isNegativeWeightCycle(n, edges))
        cout << "Yes, Negative weight cycle exists\n";
    else
        cout << "No, Negative weight cycle\n";

    return 0;
}