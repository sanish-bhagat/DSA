#include <bits/stdc++.h>
using namespace std;

// check whether the cell is in-bound or not
bool isSafe(int i, int j, int n, int m)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}

//! TC is O(n * m)
//! SC is O(n * m)

int orangesRot(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // BFS -> stores the coordinates
    queue<pair<int, int>> q;

    // push the initially rotten cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
                q.push({i, j});
        }
    }

    // 4 traversal direction for every cell
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int reqTime = 0;

    // perform bfs
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;

        // process all oranges at curr level of time
        for (int i = 0; i < size; i++)
        {
            auto front = q.front();
            q.pop();

            int x = front.first, y = front.second;

            // check for all 4 directions
            for (int i = 0; i < dir.size(); i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                // valid cell -> can rot the fresh orange
                if (isSafe(nx, ny, n, m) && mat[nx][ny] == 1)
                {
                    mat[nx][ny] += 1;

                    // push the curr rotten cell
                    q.push({nx, ny});
                    flag = true;
                }
            }
        }

        // if atleast one orange have rotten, increase the time
        if (flag)
            reqTime++;
    }

    // check if any orange is left fresh
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                return -1;
        }
    }

    return reqTime;
}

int main()
{
    vector<vector<int>> mat = {{2, 1, 0, 2, 1},
                               {1, 0, 1, 2, 1},
                               {1, 0, 0, 2, 1}};
    cout << orangesRot(mat);
    return 0;
}