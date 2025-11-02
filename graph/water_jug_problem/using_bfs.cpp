#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int minSteps(int m, int n, int d)
{
    if (d > max(n, m))
        return -1;

    vector<vector<bool>> vis(m + 1, vector<bool>(n + 1, false));
    queue<vector<int>> q;

    vis[0][0] = true;
    q.push({0, 0, 0});

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int jug1 = curr[0], jug2 = curr[1], steps = curr[2];

        // reached the target
        if (jug1 == d || jug2 == d)
            return steps;

        // fill jug1
        if (!vis[m][jug2])
        {
            vis[m][jug2] = true;
            q.push({m, jug2, steps + 1});
        }

        // fill jug2
        if (!vis[jug1][n])
        {
            vis[jug1][n] = true;
            q.push({jug1, n, steps + 1});
        }

        // empty jug1
        if (!vis[0][jug2])
        {
            vis[0][jug2] = true;
            q.push({0, jug2, steps + 1});
        }

        // empty jug2
        if (!vis[jug1][0])
        {
            vis[jug1][0] = true;
            q.push({jug1, 0, steps + 1});
        }

        // pour jug1 to jug2
        int pour1to2 = min(jug1, n - jug2);
        if (!vis[jug1 - pour1to2][jug2 + pour1to2])
        {
            vis[jug1 - pour1to2][jug2 + pour1to2] = true;
            q.push({jug1 - pour1to2, jug2 + pour1to2, steps + 1});
        }

        // pour jug2 to jug1
        int pour2to1 = min(jug2, m - jug1);
        if (!vis[jug1 + pour2to1][jug2 - pour2to1])
        {
            vis[jug1 + pour2to1][jug2 - pour2to1] = true;
            q.push({jug1 + pour2to1, jug2 - pour2to1, steps + 1});
        }
    }

    return -1;
}

int main()
{
    // jug1 = 4 litre, jug2 = 3 litre
    int m = 4, n = 3, d = 2;
    cout << minSteps(m, n, d);
    return 0;
}