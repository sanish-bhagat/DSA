#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int minSteps(vector<int> &knightPos, vector<int> &targetPos, int n)
{
    // moves for all 8 directions
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    // visited bool array
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

    // for BFS traversal, {x-pos, y-pos, dist}
    queue<array<int, 3>> q;

    int startX = knightPos[0];
    int startY = knightPos[1];
    int targetX = targetPos[0];
    int targetY = targetPos[1];

    // start from the inital position of the knight
    vis[startX][startY] = true;
    q.push({startX, startY, 0});

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        // get the curr pos and dist
        int x = node[0], y = node[1], dist = node[2];

        // reached the target position
        if (x == targetX && y == targetY)
            return dist;

        // check in all 8 positions
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // new position lies in board and not previously visited
            if (nx <= n && nx >= 1 && ny <= n && ny >= 1 && !vis[nx][ny])
            {
                // mark the new position as visited
                vis[nx][ny] = true;

                // update the dist
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 30;
    vector<int> knightPos = {1, 1};
    vector<int> targetPos = {30, 30};
    cout << minSteps(knightPos, targetPos, n);
    return 0;
}