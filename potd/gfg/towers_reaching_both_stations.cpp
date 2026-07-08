#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int n, int m, vector<vector<int>> &mat, queue<pair<int, int>> &q, vector<vector<bool>> &vis)
{
    // moving directions
    vector<int> dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto cell = q.front();
        q.pop();

        int r = cell.first;
        int c = cell.second;

        // try all possible 4 directions
        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            // cell is valid and signal of new tower is more than the curr tower, visit it
            if (isValid(nr, nc, n, m) && !vis[nr][nc] && mat[nr][nc] >= mat[r][c])
            {
                vis[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

//! TC is O(n * m)
//! SC is O(n * m)

int countCoordinates(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // stores cell coordinates
    queue<pair<int, int>> stationP, stationQ;

    // keep track of coordinates that can reach station
    vector<vector<bool>> reachP(n, vector<bool>(m, false));
    vector<vector<bool>> reachQ(n, vector<bool>(m, false));

    // towers adjacent to P(top boundary)
    // towers adjacent to Q(bottom boundary)
    for (int j = 0; j < m; j++)
    {
        stationP.push({0, j});
        reachP[0][j] = true;
        ;

        stationQ.push({n - 1, j});
        reachQ[n - 1][j] = true;
    }

    // towers adjacent to P(left boundary)
    // towers adjacent to Q(right boundary)
    for (int i = 0; i < n; i++)
    {
        stationP.push({i, 0});
        reachP[i][0] = true;

        stationQ.push({i, m - 1});
        reachQ[i][m - 1] = true;
    }

    // perform bfs and find all the cells(towers) that can reach stations
    bfs(n, m, mat, stationP, reachP);
    bfs(n, m, mat, stationQ, reachQ);

    // count towers reachable from both stations
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (reachP[i][j] && reachQ[i][j])
                cnt++;
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 2, 3, 5},
                               {3, 2, 3, 4, 4},
                               {2, 4, 5, 3, 1},
                               {6, 7, 1, 4, 5},
                               {5, 1, 1, 2, 4}};

    cout << countCoordinates(mat) << endl;

    return 0;
}