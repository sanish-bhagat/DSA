#include <bits/stdc++.h>
using namespace std;
#define INF 9999

//! TC is O(n^3)
//! SC is O(1)

bool negCyclefloydWarshall(vector<vector<int>> &graph)
{
    int n = graph.size();

    // dist[][] copy
    vector<vector<int>> dist = graph;

    // traverse every vertex treating it as source
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // find the shortest distance, having 'k' as an intermediate vertex
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][i]);
            }
        }
    }

    // detect negative cycle ->
    // after performing the algo, if any vertex has negative weight to reach itself
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
            return true;
    }

    return false;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, INF, INF},
                                 {INF, 0, -1, INF},
                                 {INF, INF, 0, -1},
                                 {-1, INF, INF, 0}};

    if (negCyclefloydWarshall(graph))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}