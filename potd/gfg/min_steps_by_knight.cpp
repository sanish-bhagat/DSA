#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int n, vector<int> &knightPos, vector<int> &targetPos)
{
    // keep track of visited cells
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));

    // start and target cell coordinates
    int startX = knightPos[0], startY = knightPos[1];
    int targetX = targetPos[0], targetY = targetPos[1];

    // moving directions
    vector<int> dx = {2, -2, 2, -2, 1, -1, 1, -1};
    vector<int> dy = {1, 1, -1, -1, 2, 2, -2, -2};

    // BFS -> {x, y, dist}
    queue<vector<int>> q;

    q.push({startX, startY, 0});
    vis[startX][startY] = true;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int x = front[0], y = front[1], dist = front[2];

        // reached the target cell
        if (x == targetX && y == targetY)
            return dist;

        // explore all possible directions
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // explore the next valid move
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 6;
    vector<int> knightPos = {1, 3}, targetPos = {5, 1};

    cout << minStepToReachTarget(n, knightPos, targetPos);
}