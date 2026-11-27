#include <bits/stdc++.h>
using namespace std;

//! TC is O(V + E)
//! SC is O(1)

int countEdges(vector<vector<int>> &adj)
{
    int sum = 0;

    // traverse all vertices and add the size of their adjacency lists
    for (auto neighbors : adj)
        sum += neighbors.size();

    // each edge is counted twice in an undirected graph
    return sum / 2;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    cout << countEdges(adj) << endl;

    return 0;
}