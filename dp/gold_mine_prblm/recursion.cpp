#include <bits/stdc++.h>
using namespace std;

int maxGoldRec(int x, int y, vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // base case
    if (x < 0 || x >= n || y >= m)
        return 0;

    // move to right upper cell
    int rightUpper = maxGoldRec(x - 1, y + 1, mat);

    // move to right cell
    int right = maxGoldRec(x, y + 1, mat);

    // move to right lower cell
    int rightLower = maxGoldRec(x + 1, y + 1, mat);

    // return the max gold collected from the three moves
    return mat[x][y] + max(max(rightUpper, right), rightLower);
}

//! TC is O(3 ^ (n * m))
//! SC is O(n * m)

int maxGold(vector<vector<int>> &mat)
{
    int n = mat.size();

    int res = 0;

    // explore every path, starting from each cell in the first column
    for (int i = 0; i < n; i++)
    {
        int gold = maxGoldRec(i, 0, mat);
        res = max(res, gold);
    }

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