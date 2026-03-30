#include <bits/stdc++.h>
using namespace std;

// returns the manhattan distance of two points
int manhattanDist(vector<int> &a, vector<int> &b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

//! TC is O(n * n * logn)
//! SC is O(n * n)

int minCost(vector<vector<int>> &houses)
{
    int n = houses.size();

    // min heap -> {cost, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // keep track of visited nodes
    vector<bool> visited(n, false);

    // start with the house 0
    pq.push({0, 0});

    int totalCost = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        // curr cost and house
        int cost = top.first;
        int u = top.second;

        // skip house, if already visited
        if (visited[u])
            continue;

        // include the cost and mark the house as visited
        totalCost += cost;
        visited[u] = true;

        // calculate dist to all unvisited houses and include it in the heap
        for (int v = 0; v < n; v++)
        {

            if (!visited[v])
            {
                int dist = manhattanDist(houses[u], houses[v]);
                pq.push({dist, v});
            }
        }
    }

    return totalCost;
}

int main()
{

    vector<vector<int>> houses = {
        {0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};

    int result = minCost(houses);

    cout << result << endl;

    return 0;
}