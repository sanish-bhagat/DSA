#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &mat, int i, int j, int xd, int yd)
{
    int n = mat.size(), m = mat[0].size();

    // base case: reached the destination
    if (i == xd && j == yd)
        return 0;

    // base case: out of bound index or curr cell is blocked
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == 0)
        return -1;

    // mark the cell as visited
    mat[i][j] = 0;

    // four possible moves
    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};

    int maxLength = -1;

    // check in all possible directions and recursively calculate the longest path
    for (int k = 0; k < 4; k++)
    {
        int ni = i + row[k];
        int nj = j + col[k];

        // recursive function from new source cell to final destination
        int pathLength = dfs(mat, ni, nj, xd, yd);

        // update the maxLength
        if (pathLength != -1)
            maxLength = max(maxLength, pathLength + 1);
    }

    // backtrack: unmark the curr cell
    mat[i][j] = 1;

    return maxLength;
}

//! TC is O(4^(n * m))
//! SC is O(1)

int findLongestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
{
    // source or destination is blocked
    if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
        return -1;

    // recursive function to get the longest path
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

    int result = findLongestPath(mat, xs, ys, xd, yd);

    if (result != -1)
        cout << result << endl;
    else
        cout << -1 << endl;

    return 0;
}