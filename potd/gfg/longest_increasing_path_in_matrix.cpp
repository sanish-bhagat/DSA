#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int pathRec(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &memo)
{
    // already visited cell
    if (memo[i][j] != -1)
        return memo[i][j];

    int n = matrix.size(), m = matrix[0].size();

    // moving directions
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    // include curr cell in the ans
    int ans = 1;

    // explore all the moves
    for (int k = 0; k < 4; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];

        // visit the next valid cell
        if (isValid(ni, nj, n, m) && matrix[i][j] < matrix[ni][nj])
            ans = max(ans, 1 + pathRec(ni, nj, matrix, memo));
    }

    return memo[i][j] = ans;
}

//! TC is O(n * m)
//! SC is O(n * m)

int longIncPath(vector<vector<int>> &matrix, int n, int m)
{
    // 2d dp table
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    int ans = 0;

    // check longest increasing path for each cell
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            ans = max(ans, pathRec(i, j, matrix, memo));
    }

    return ans;
}

int main()
{
    int n = 3, m = 3;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << longIncPath(matrix, n, m) << endl;

    return 0;
}