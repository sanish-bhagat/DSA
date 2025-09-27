#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool findPath(unordered_map<int, vector<pair<int, int>>> &adj, int src, int k, vector<int> &visited)
    {
        // base case: if path length <= 0 -> founded a path, return true
        if (k <= 0)
            return true;

        // traverse each neighbor(v, w) of src
        for (auto i : adj[src])
        {
            int v = i.first, w = i.second;

            // already visited, avoid cycle
            if (visited[v] == 1)
                continue;

            // mark the curr node as visited
            visited[v] = 1;

            // recursively find for src -> v and path length -> (k - w)(left out path length)
            if (findPath(adj, v, k - w, visited))
                return true;

            // bactrack to explore more paths
            visited[v] = 0;
        }

        // no path found, after exploring all the neighbors
        return false;
    }

public:
    //! TC is O(V!)
    //! SC is O(V)

    bool pathMoreThanK(int V, int E, int K, int *a)
    {
        // adjaceny list, each entry keeps(neighbor, weight)
        unordered_map<int, vector<pair<int, int>>> adj;

        // fill the adjaceny list(undirected graph, so add both u -> v and v -> u)
        for (int i = 0; i < 3 * E; i += 3)
        {
            int u = a[i], v = a[i + 1], w = a[i + 2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   // undirected garph
        }

        // visited to avoid cycle
        vector<int> visited(V, 0);

        // mark the source node as visited
        visited[0] = 1;

        // recursive function
        return findPath(adj, 0, K, visited);
    }
};

int main()
{
    // Example 1: output = 0
    {
        int V = 4, E = 3, K = 8;
        int A[] = {0, 1, 5, 1, 2, 1, 2, 3, 1};
        Solution sol;
        cout << sol.pathMoreThanK(V, E, K, A) << endl; // Expected 0
    }

    // Example 2: output = 1
    {
        int V = 4, E = 3, K = 4;
        int A[] = {0, 1, 5, 1, 2, 1, 2, 3, 1};
        Solution sol;
        cout << sol.pathMoreThanK(V, E, K, A) << endl; // Expected 1
    }

    return 0;
}