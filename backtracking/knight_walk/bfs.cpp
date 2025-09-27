#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // checks whether the move lies int the board or not
    bool isValid(int x, int y, int N)
    {
        return (x >= 1 && x <= N && y >= 1 && y <= N);
    }

    //! TC is O(n * n)
    //! SC is O(n * n)

public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // base case: reached the target
        if (KnightPos == TargetPos)
            return 0;

        // knight move's coordinates
        int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
        int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

        // visited[] to track visited cells
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

        // queue to push the moves: push the first move and its dist
        queue<array<int, 3>> q;
        q.push({KnightPos[0], KnightPos[1], 0});

        // mark the curr cell as visited
        visited[KnightPos[0]][KnightPos[1]] = true;

        while (!q.empty())
        {
            // fetch the cell and distance
            auto front = q.front();
            int x = front[0], y = front[1], dist = front[2];
            q.pop();

            // try all the 8 possible moves
            for (int i = 0; i < 8; i++)
            {
                // next move
                int nx = x + dx[i], ny = y + dy[i];

                // if next move is valid and not visited
                if (isValid(nx, ny, N) && !visited[nx][ny])
                {
                    // reached to the target
                    if (nx == TargetPos[0] && ny == TargetPos[1])
                        return dist + 1;

                    // mark the cell as visited
                    visited[nx][ny] = true;

                    // push the move and dist into the queue
                    q.push({nx, ny, dist + 1});
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int N = 5;
    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};

    cout << sol.minStepToReachTarget(KnightPos, TargetPos, N) << endl;
    return 0;
}