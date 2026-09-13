#include <bits/stdc++.h>
using namespace std;

pair<int, int> bfs(vector<vector<int>> &adj, int start)
{
    int n = adj.size();

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    int farthestNode = start;
    int farthestDist = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : adj[node])
        {
            // Convert 1-based house number to 0-based index.
            next--;

            if (dist[next] == -1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);

                // Update the farthest house.
                if (dist[next] > farthestDist)
                {
                    farthestDist = dist[next];
                    farthestNode = next;
                }
            }
        }
    }

    return {farthestNode, farthestDist};
}

//! TC is O(n)
//! SC is O(n)

int partyHouse(vector<vector<int>> &adj)
{
    int n = adj.size();

    // First BFS:
    // Find one endpoint of the tree's diameter.
    pair<int, int> first = bfs(adj, 0);
    int diameterEnd = first.first;

    // Second BFS:
    // Starting from the diameter endpoint,
    // find the actual diameter length.
    pair<int, int> second = bfs(adj, diameterEnd);
    int diameter = second.second;

    // The optimal party house is at the center
    // of the diameter.
    // ceil(diameter / 2) = (diameter + 1) / 2
    return (diameter + 1) / 2;
}

int main()
{
    vector<vector<int>> adj = {
        {2},
        {1, 3},
        {2, 4},
        {3},
    };

    cout << partyHouse(adj) << endl;

    return 0;
}