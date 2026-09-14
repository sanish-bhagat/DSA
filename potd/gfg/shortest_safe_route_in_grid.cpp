#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &mat, int i, int j)
{
    int r = mat.size();
    int c = mat[0].size();

    // cell is a landmine or already visited
    if (mat[i][j] != 1)
        return false;

    // moving directions
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        // curr cell is adjacent to a landmine
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && mat[ni][nj] == 0)
            return false;
    }

    return true;
}

//! TC is O(n * m)
//! SC is O(n * m)

int shortestPath(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();

    // moving directions
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    // {i, j, dist}
    queue<array<int, 3>> q;

    // push all the the safe cells in the first column
    for (int i = 0; i < r; i++)
    {
        if (isSafe(mat, i, 0))
        {
            q.push({i, 0, 1});

            // mark as visited
            mat[i][0] = -1;
        }
    }

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        int i = front[0], j = front[1], d = front[2];

        // reached the last column
        if (j == c - 1)
            return d;

        // try all possible 4 directions
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < r && nj >= 0 && nj < c && isSafe(mat, ni, nj))
            {
                q.push({ni, nj, d + 1});

                mat[ni][nj] = -1;
            }
        }
    }

    // no path found
    return -1;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};

    int result = shortestPath(mat);
    cout << result << endl;

    return 0;
}