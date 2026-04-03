#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

vector<int> diagonalTraversal(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    vector<int> res;

    // start from 1st row
    for (int col = 0; col < m; col++)
    {
        int i = 0, j = col;

        // keep on traversing diagonaly downwards
        while (i < n && j >= 0)
        {
            res.push_back(mat[i][j]);
            i++, j--;
        }
    }

    // start from last column, excluding the 1st row
    for (int row = 1; row < n; row++)
    {
        int i = row, j = m - 1;

        // keep on traversing diagonaly downwards
        while (i < n && j >= 0)
        {
            res.push_back(mat[i][j]);
            i++, j--;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> res = diagonalTraversal(mat);

    for (int x : res)
        cout << x << " ";

    return 0;
}