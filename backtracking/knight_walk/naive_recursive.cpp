#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // knight move's coordinates
    int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

public:
    // checks whether the move lies int the board or not
    int isValid(int x, int y, int N)
    {
        return (x >= 1 && x <= N && y >= 1 && y <= N);
    }

    int dfs(int x, int y, int tx, int ty, int N, vector<vector<bool>> &visited)
    {
        // reached the target
        if (x == tx && y == ty)
            return 0;

        // mark the curr cell
        visited[x][y] = true;
        int ans = INT_MAX;

        // all possible 8 moves
        for (int i = 0; i < 8; i++)
        {
            // next move
            int nx = x + dx[i], ny = y + dy[i];

            // if move is valid and not visited
            if (isValid(nx, ny, N) && !visited[nx][ny])
            {
                // recursive call
                int res = dfs(nx, ny, tx, ty, N, visited);

                // update the ans
                if (res != INT_MAX)
                    ans = min(ans, res + 1);
            }
        }

        // backtrack: unmark curr cell
        visited[x][y] = false;

        return ans;
    }

    //! TC is O(8 ^ d)
    //! SC is O(n * n)

    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // visited[] to track visited cells
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

        int ans = dfs(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N, visited);

        return (ans == INT_MAX) ? -1 : ans;
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
