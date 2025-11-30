#include <bits/stdc++.h>
using namespace std;

int maxSquareRec(int i, int j, vector<vector<int>> &mat, int &ans)
{
    // base case: cell out of bound
    if (i < 0 || i == mat.size() || j < 0 || j == mat[0].size())
        return 0;

    // explore all the ways: right, down and bottom-diagonal
    int right = maxSquareRec(i, j + 1, mat, ans);
    int down = maxSquareRec(i + 1, j, mat, ans);
    int diagonal = maxSquareRec(i + 1, j + 1, mat, ans);

    // curr cell value is 0: can't contribute into the square
    if (mat[i][j] == 0)
        return 0;

    // pick the largest possible square
    int len = 1 + min({right, down, diagonal});

    // pick the max length of the square sub-matrix
    ans = max(ans, len);

    return len;
}

//! TC is O(3^(n + m))
//! SC is O(n + m)

int maxSquare(vector<vector<int>> &mat)
{
    int ans = 0;
    maxSquareRec(0, 0, mat, ans);

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