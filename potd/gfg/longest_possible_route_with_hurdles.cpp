#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &mat, int i, int j, int x, int y)
{
    int n = mat.size(), m = mat[0].size();

    // destination reached
    if (i == x && j == y)
        return 0;

    // not valid cell or already visited
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0)
        return -1;

    // mark cell as visited
    mat[i][j] = 0;

    int maxPath = -1;

    // moving directions
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        // visit the new cell
        int pathLength = dfs(mat, ni, nj, x, y);

        // if path is valid -> update the maxLength
        if (pathLength != -1)
            maxPath = max(maxPath, pathLength + 1);
    }

    // backtrack, restore the original value
    mat[i][j] = 1;

    return maxPath;
}

//! TC is O(4 * (n * m))
//! SC is O(1)

int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
{
    // source or destination cell is blocked
    if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
        return -1;

    return dfs(mat, xs, ys, xd, yd);
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    int xs = 0, ys = 0;
    int xd = 1, yd = 7;

    cout << longestPath(mat, xs, ys, xd, yd);

    return 0;
}