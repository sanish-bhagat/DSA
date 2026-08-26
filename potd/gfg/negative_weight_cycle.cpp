#include <bits/stdc++.h>
using namespace std;

//! TC is O(V * E)
//! SC is O(V)

bool isNegativeWeightCycle(int V, vector<vector<int>> &edges)
{
    // shortest dist to reach v from u
    vector<int> dist(V, 0);

    // relax the edges (V - 1) times
    for (int i = 0; i < V - 1; i++)
    {
        bool changed = false;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            // relax the edge
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }

        // no relaxation -> no negative weight cycle
        if (!changed)
            return false;
    }

    // if we are able to relax the edge 1more time,
    // then negative weight cycle present
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        // negative weight cycle -> return true
        if (dist[u] + w < dist[v])
            return true;
    }

    // no negative weight cycle -> return false
    return false;
}

int main()
{
    int V = 4;

    vector<vector<int>> edges = {
        {0, 3, 6},
        {1, 0, 4},
        {1, 2, 6},
        {3, 1, 2}};

    cout << isNegativeWeightCycle(V, edges);
}