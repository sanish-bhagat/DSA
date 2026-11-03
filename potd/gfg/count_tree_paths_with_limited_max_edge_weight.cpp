#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

int ans;

// Find the representative of a set.
int root(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;

    return parent[x] = root(parent[x], parent);
}

// Union two components.
void Union(int a, int b, vector<int> &parent, vector<int> &sz)
{
    int ra = root(a, parent);
    int rb = root(b, parent);

    // Already in the same component.
    if (ra == rb)
        return;

    // Union by size.
    if (sz[ra] < sz[rb])
        swap(ra, rb);

    // Every node in one component can form a path
    // with every node in the other component.
    ans += sz[ra] * sz[rb];

    parent[rb] = ra;
    sz[ra] += sz[rb];
}

//! TC is O(n log n + q log n)
//! SC is O(n)

vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int> &queries)
{
    ans = 0;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    // Store {weight, u, v}.
    vector<array<int, 3>> wt;

    for (auto &e : edges)
    {
        wt.push_back({e[2], e[0], e[1]});
    }

    // Sort edges by weight.
    sort(wt.begin(), wt.end());

    // weight -> number of valid paths
    // whose maximum edge weight is <= weight.
    map<int, int> mp;

    int i = 0;

    while (i < (int)wt.size())
    {

        int weight = wt[i][0];

        // Process all edges having the same weight.
        while (i < (int)wt.size() && wt[i][0] == weight)
        {

            int u = wt[i][1];
            int v = wt[i][2];

            Union(u, v, parent, sz);

            i++;
        }

        // Store the answer after processing
        // all edges of this weight.
        mp[weight] = ans;
    }

    vector<int> res;
    res.reserve(queries.size());

    // Process every query.
    for (int x : queries)
    {

        // Find the first weight greater than x.
        auto it = mp.upper_bound(x);

        if (it == mp.begin())
        {
            res.push_back(0);
        }
        else
        {
            --it;
            res.push_back(it->second);
        }
    }

    return res;
}

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}};
    vector<int> queries = {1, 3, 5};

    vector<int> ans = maximumWeight(n, edges, queries);

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << ans[i];
    }
    cout << "]\n";

    return 0;
}