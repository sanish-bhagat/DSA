#include <bits/stdc++.h>
using namespace std;

int maxSquareRec(int i, int j, int &ans, vector<vector<int>> &mat, vector<vector<int>> &memo)
{
    // base case: cell out of bound
    if (i < 0 || i == mat.size() || j < 0 || j == mat[0].size())
        return 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    // explore all the ways: right, down and bottom-diagonal
    int right = maxSquareRec(i, j + 1, ans, mat, memo);
    int down = maxSquareRec(i + 1, j, ans, mat, memo);
    int diagonal = maxSquareRec(i + 1, j + 1, ans, mat, memo);

    // curr cell value is 0: can't contribute into the square
    if (mat[i][j] == 0)
        return 0;

    // pick the largest possible square for the curr cell
    int len = 1 + min({right, down, diagonal});

    // pick the max length of the square sub-matrix
    ans = max(ans, len);

    // return the largest possible sqaure length of the curr cell 
    return memo[i][j] = len;
}

//! TC is O(n * m)
//! SC is O(n * m)

int maxSquare(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 2d memo[][]
    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
    int ans = 0;

    maxSquareRec(0, 0, ans, mat, memo);

    return ans;
}

int main()
{
    vector<vector<int>> mat =
        {{0, 1, 1, 0, 1},
         {1, 1, 0, 1, 0},
         {0, 1, 1, 1, 0},
         {1, 1, 1, 1, 0},
         {1, 1, 1, 1, 1},
         {0, 0, 0, 0, 0}};
    cout << maxSquare(mat) << endl;

    return 0;
}