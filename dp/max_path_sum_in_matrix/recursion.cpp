#include <bits/stdc++.h>
using namespace std;

int maxSumRec(int i, int j, vector<vector<int>> &mat)
{
    // base case: out of bound -> invalid moves
    if (j < 0 || j >= mat[0].size())
        return 1e-9;

    // base case: reached beyond last row -> end of path
    if (i == mat.size())
        return 0;

    // recursively move to three directions
    int down = maxSumRec(i + 1, j, mat);
    int left = maxSumRec(i + 1, j - 1, mat);
    int right = maxSumRec(i + 1, j + 1, mat);

    // include the max sum of the three moves in the curr path
    return mat[i][j] + max({down, left, right});
}

//! TC is O(m * 3 ^ n)
//! SC is O(n)

int maximumPath(vector<vector<int>> &mat)
{
    int sum = 0;

    // start from every column of the first row and pick the path with the max sum
    for (int j = 0; j < mat[0].size(); j++)
    {
        sum = max(sum, maxSumRec(0, j, mat));
    }

    return sum;
}

int main()
{

    // Input matrix
    vector<vector<int>> mat = {{10, 10, 2, 0, 20, 4},
                               {1, 0, 0, 30, 2, 5},
                               {0, 10, 4, 0, 2, 0},
                               {1, 0, 2, 20, 0, 4}};

    // Output the maximum path sum
    cout << maximumPath(mat) << endl;
    return 0;
}