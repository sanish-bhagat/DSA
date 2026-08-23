#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    if (mat[r][c] == '#')
        return 0;

    // best[i][j] = minimum number of upward moves
    // used to reach (i,j)
    vector<vector<int>> best(n, vector<int>(m, INT_MAX));

    // queue for BFS traversal
    queue<pair<int, int>> q;

    best[r][c] = 0;
    q.push({r, c});

    // moving directions
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int x = front.first;
        int y = front.second;

        // up directions used to reach curr cell
        int upUsed = best[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // invalid cell
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || mat[nx][ny] == '#')
                continue;

            int newUp = upUsed;

            // up direction
            if (i == 1)
                newUp++;

            // down moves used
            int downUsed = newUp + nx - r;

            // moves greater than given constraint
            if (upUsed > u || downUsed > d)
                continue;

            // try to minimise the up moves
            if (newUp < best[nx][ny])
            {
                best[nx][ny] = newUp;
                q.push({nx, ny});
            }
        }
    }

    // Every finite best[][] represents one reachable cell.
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (best[i][j] != INT_MAX)
                ans++;
    }

    return ans;
}

int main()
{
    vector<vector<char>> mat = {{'.', '.', '.'}, {'.', '#', '.'}, {'#', '.', '.'}};

    int r = 1;
    int c = 0;
    int u = 1;
    int d = 1;

    cout << numberOfCells(r, c, u, d, mat) << endl;

    return 0;
}