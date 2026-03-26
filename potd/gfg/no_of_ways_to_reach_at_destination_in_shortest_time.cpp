#include <bits/stdc++.h>
using namespace std;

//! TC is O(V + ElogE)
//! SC is O(V + E)

int countPaths(int V, vector<vector<int>> &edges)
{
    // build the weighted adjacency matrix for the undirected graph
    vector<vector<pair<int, int>>> adj(V);
    for (auto e : edges)
    {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    // keep track of minTime required to reach the node from source(0)
    vector<int> minTime(V, INT_MAX);

    // no. of shortest paths that lead to the curr node
    vector<int> paths(V, 0);

    minTime[0] = 0;
    paths[0] = 1;

    // min heap -> {time req, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int node = top.second;
        int currTime = top.first;

        // we already have a min Time path
        if (currTime > minTime[node])
            continue;

        // visit all the neighbors of the curr node
        for (auto next : adj[node])
        {
            int nextNode = next.first;
            int nextTime = next.second;

            // newTime to reach the curr node
            int newTime = currTime + nextTime;

            // newTime is less -> update time and path
            if (newTime < minTime[nextNode])
            {
                minTime[nextNode] = newTime;
                paths[nextNode] = paths[node];
                pq.push({newTime, nextNode});
            }

            // time is same -> increment the count of paths
            else if (newTime == minTime[nextNode])
                paths[nextNode] += paths[node];
        }
    }

    // return the no. of paths req to reach the destination in min time
    return paths[V - 1];
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {0, 3, 5}, {1, 3, 3}, {2, 3, 4}};
    cout << countPaths(V, edges);
}