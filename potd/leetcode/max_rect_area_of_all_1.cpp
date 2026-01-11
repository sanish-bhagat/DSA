#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int maximalRect(vector<vector<char>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // 1d height[] -> no. of consecutive 1s vertically ending at (i, j)
    // left[] -> leftmost boundary of rectangle ending at (i, j)
    // right[] -> rightmost boundary of rectangle ending at (i, j)
    vector<int> height(m, 0), left(m, 0), right(m, m);
    int maxArea = 0;

    // traverse every cell in the matrix
    for (int i = 0; i < n; i++)
    {
        int currLeft = 0, currRight = m;

        // update height -> increase if curr cell is 1 else reset it to 0
        for (int j = 0; j < m; j++)
            height[j] = (mat[i][j] == '1') ? height[j] + 1 : 0;

        // update left -> leftmost boundary
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '1')
                left[j] = max(left[j], currLeft);

            else
            {
                left[j] = 0;
                currLeft = j + 1;
            }
        }

        // update right -> rightmost boundary
        for (int j = m - 1; j >= 0; j--)
        {
            if (mat[i][j] == '1')
                right[j] = min(right[j], currRight);

            else
            {
                right[j] = m;
                currRight = j;
            }
        }

        // calculate area
        for (int j = 0; j < m; j++)
            maxArea = max(maxArea, height[j] * (right[j] - left[j]));
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> mat = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << maximalRect(mat);
}