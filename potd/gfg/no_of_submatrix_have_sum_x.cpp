#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * m)
//! SC is O(m)

int countSquare(vector<vector<int>> &mat, int x)
{
    int n = mat.size(), m = mat[0].size(), count = 0;

    // fix top
    for (int top = 0; top < n; top++)
    {
        // prefixSum[] -> col elements sum
        vector<int> colSum(m, 0);

        // fix bottom
        for (int bottom = top; bottom < n; bottom++)
        {
            // build the colSum[]
            for (int col = 0; col < m; col++)
                colSum[col] += mat[bottom][col];

            // curr height of the square
            int k = bottom - top + 1;

            // can't form a square -> skip
            if (k > m)
                continue;

            // sliding window of size k
            int windowSum = 0;
            for (int col = 0; col < m; col++)
            {
                // include in the curr window
                windowSum += colSum[col];

                // out of window(square) elements -> exclude
                if (col >= k)
                    windowSum -= colSum[col - k];

                // valid square of size k -> sum of square submatrix == X -> include in the count
                if (col >= k - 1)
                    if (windowSum == x)
                        count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> mat = {
        {2, 4, 7, 8, 10},
        {3, 1, 1, 1, 1},
        {9, 11, 1, 2, 1},
        {12, -17, 1, 1, 1}};

    int x = 10;

    int res = countSquare(mat, x);
    cout << res << endl;
    return 0;
}