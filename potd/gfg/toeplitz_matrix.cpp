#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! Sc is O(1)

bool isToeplitz(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // check every element checks its top-left neighbor
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            // value mismatches -> return false
            if (mat[i][j] != mat[i - 1][j - 1])
                return false;
        }
    }

    // valid matrix
    return true;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 1, 2},
        {7, 4, 1},
        {8, 7, 9}};

    cout << isToeplitz(mat);
}