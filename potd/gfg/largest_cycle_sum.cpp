#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int largestSumCycle(vector<int> &edge)
{
    int n = edge.size();

    // keep track of visited edges
    vector<bool> vis(n, false);

    // keep track of edges in curr path
    vector<bool> currPath(n, false);

    int maxi = -1;

    // iterate through every edge
    for (int i = 0; i < n; i++)
    {
        // already explored cell
        if (vis[i])
            continue;

        // traverse the path from node i
        int curr = i;
        vector<int> path;

        // traverse the path until valid starting from curr
        while (curr != -1 && !vis[curr])
        {
            vis[curr] = true;
            currPath[curr] = true;
            path.push_back(curr);
            curr = edge[curr];
        }

        // curr is reached again in the active path -> cycle detected
        if (curr != -1 && currPath[curr])
        {
            int sum = 0;

            // find the path sum, starting from curr to end of the cycle
            for (int j = path.size() - 1; j >= 0; j--)
            {
                sum += path[j];

                if (curr == path[j])
                    break;
            }

            maxi = max(maxi, sum);
        }

        // reset currPath for the nodes traversed in the curr iteration
        for (int u : path)
            currPath[u] = false;
    }

    return maxi;
}

int main()
{
    vector<int> edge = {1, 2, 0, -1};

    cout << largestSumCycle(edge);
}