#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n)

int maxGold(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 1D[] to keep track of the previous row
    vector<int> prev(n, 0);

    // fill with the given last column gold values
    for (int i = 0; i < n; i++)
        prev[i] = mat[i][m - 1];

    // move right to left
    for (int y = m - 2; y >= 0; y--)
    {
        // curr column values
        vector<int> curr(n, 0);

        // explore all the three moves and pick the max one
        for (int x = 0; x < n; x++)
        {
            int rightUpper = (x > 0) ? prev[x - 1] : 0;

            int right = prev[x];

            int rightLower = (x < n - 1) ? prev[x + 1] : 0;

            curr[x] = mat[x][y] + max(max(rightUpper, right), rightLower);
        }

        // swaap prev and curr for the next round
        prev = curr;
    }

    // pick the max value from the final prev[]
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, prev[i]);

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