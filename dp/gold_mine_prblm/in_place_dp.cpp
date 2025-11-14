#include <bits/stdc++.h>
using namespace std;

// checks if cell is in-bound or not
bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

//! TC is O(n * m)
//! SC is O(1)

int maxGold(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // traverse from right to left
    for (int y = m - 2; y >= 0; y--)
    {
        for (int x = 0; x < n; x++)
        {
            int maxPrev = 0;

            // right upper cell
            if (isValid(x - 1, y + 1, n, m))
                maxPrev = max(maxPrev, mat[x - 1][y + 1]);

            // right cell
            if (isValid(x, y + 1, n, m))
                maxPrev = max(maxPrev, mat[x][y + 1]);

            // right lower cell
            if (isValid(x + 1, y + 1, n, m))
                maxPrev = max(maxPrev, mat[x + 1][y + 1]);

            // update the cell with the max value from the three options
            mat[x][y] += maxPrev;
        }
    }

    // pick the max value from the first column
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, mat[i][0]);

    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}};

    cout << maxGold(mat) << endl;
    return 0;
}