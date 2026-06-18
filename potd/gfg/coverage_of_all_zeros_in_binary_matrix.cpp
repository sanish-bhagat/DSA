#include <bits/stdc++.h>
using namespace std;

//! Tc is O(n * m)
//! SC is O(1)

int findCoverage(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    int res = 0;

    // for every row, traverse from left to right and
    // then from right to left
    for (int i = 0; i < n; i++)
    {
        bool isOne = false;

        // traverse from left to right
        for (int j = 0; j < m; j++)
        {
            // 1 is encountered
            if (mat[i][j] == 1)
                isOne = true;

            // curr cell contains 0, and we have already seen a 1 before
            else if (isOne)
                res++;
        }

        isOne = false;

        // traverse from right to left
        for (int j = m - 1; j >= 0; j--)
        {
            if (mat[i][j] == 1)
                isOne = true;

            else if (isOne)
                res++;
        }
    }

    // for every column, traverse from up to down and
    // then from down to up
    for (int j = 0; j < m; j++)
    {
        bool isOne = false;

        // taverse from up to down
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] == 1)
                isOne = true;

            else if (isOne)
                res++;
        }

        isOne = false;

        // traverse from down to up
        for (int i = n - 1; i >= 0; i--)
        {
            if (mat[i][j] == 1)
                isOne = true;

            else if (isOne)
                res++;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 0, 0}};

    cout << findCoverage(mat);

    return 0;
}