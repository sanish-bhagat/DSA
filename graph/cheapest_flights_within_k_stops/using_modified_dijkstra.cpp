#include <bits/stdc++.h>
using namespace std;

int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // build the adjacency matrix for the weighted graph
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights)
        adj[it[0]].push_back({it[1], it[2]});

    // dist[] to store distances -> dist[city][stops] = cost
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

    // cost for source node
    dist[src][0] = 0;

    // min heap -> {cost, city, stops}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, src, 0});

    while (!pq.empty())
    {
        // pick the cheapest cost flight first
        auto it = pq.top();
        pq.pop();

        int cost = it[0], city = it[1], stops = it[2];

        // reached the destination -> return the cost
        if (city == dst)
            return cost;

        // too many stops, skip
        if (stops > k)
            continue;

        // explore all the neighbors(cities)
        for (auto i : adj[city])
        {
            // neighbor city and cost required to visit this city
            int next = i.first;
            int price = i.second;

            int newCost = cost + price;

            // if newCost is cheaper, then pick this route(city) and cost
            if (newCost < dist[next][stops + 1])
            {
                dist[next][stops + 1] = newCost;
                pq.push({newCost, next, stops + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 3, 500}};
    int src = 0, dst = 3, k = 1;

    int res = CheapestFlight(n, flights, src, dst, k);
    cout << res;
}