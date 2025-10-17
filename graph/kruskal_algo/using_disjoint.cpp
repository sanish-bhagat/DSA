#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        // resize to the no. of vertices
        parent.resize(n);

        // mark every vertice rank as 1
        rank.resize(n, 1);

        // every vertice is its own parent
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // find the ultimate parent of the vertice
    int find(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    // use to perform the union of two sets
    void unite(int x, int y)
    {
        int s1 = find(x), s2 = find(y);

        // both vertices have different parent
        if (s1 != s2)
        {
            // s2 set is more depper than s1 set -> join s1 to s2
            if (rank[s1] < rank[s2])
                parent[s1] = s2;

            // s1 is more deeper than s2 -> join s2 to s1
            else if (rank[s1] > rank[s2])
                parent[s2] = s1;

            else
            {
                // both are having the same depth -> join any set to any other set
                parent[s2] = s1;

                // increase the rank of the set on which the another set is joined
                rank[s1]++;
            }
        }
    }
};

// return the edge with the minimum edge weight -> helps to sort the edges in increasing order of edge-weight
bool compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int kruskalsMST(int V, vector<vector<int>> &edges)
{
    // sort the edges based on the increasing edge weight
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);
    int cost = 0, count = 0;

    // iterate through every edge and always pick the one with the min edge weight
    for (auto &e : edges)
    {
        int x = e[0], y = e[1], w = e[2];

        // check if adding an edge does not leads to a cycle
        if (dsu.find(x) != dsu.find(y))
        {
            dsu.unite(x, y);

            // add the curr edge weight to the cost
            cost += w;

            // all vertices have been connected
            if (count++ == V - 1)
                break;
        }
    }

    return cost;
}

int main()
{

    // An edge contains source, destination and weight
    vector<vector<int>> edges = {
        {0, 1, 10}, {1, 3, 15}, {2, 3, 4}, {2, 0, 6}, {0, 3, 5}};

    cout << kruskalsMST(4, edges);

    return 0;
}