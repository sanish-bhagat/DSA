#include <bits/stdc++.h>
using namespace std;

int findMaxSum(int up, int down, int left, int right, vector<vector<int>> &prefSum)
{
    // total sum from top-left corner(0, 0) to curr down-right cell
    int sum = prefSum[down][right];

    // exclude the area to the left of the curr submatrix
    if (left - 1 >= 0)
        sum -= prefSum[down][left - 1];

    // exclude the area to the upside of the submatrix
    if (up - 1 >= 0)
        sum -= prefSum[up - 1][right];

    // add back the overlapping area that was subtracted twice
    if (up - 1 >= 0 && left - 1 >= 0)
        sum += prefSum[up - 1][left - 1];

    // return the sum of the curr rectangular submatrix
    return sum;
}

//! TC is O((n * m)^ 2)
//! SC is O(n * m)

int maxRectSum(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();

    // prefSum[][] stores the sum of the submatrix from top-left corner(0, 0) to the curr cell(i, j)
    vector<vector<int>> prefSum(r, vector<int>(c, 0));

    // include the row-wise sum
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            prefSum[i][j] = mat[i][j];

            if (j - 1 >= 0)
                prefSum[i][j] += prefSum[i][j - 1];
        }
    }

    // include the column-wise sum
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i - 1 >= 0)
                prefSum[i][j] += prefSum[i - 1][j];
        }
    }

    int maxSum = INT_MIN;

    // traverse through the given matrix in a rectangular fashion
    for (int up = 0; up < r; up++)
    {
        for (int left = 0; left < c; left++)
        {
            for (int down = up; down < r; down++)
            {
                for (int right = left; right < c; right++)
                {
                    // find the sum of submatrix(top, left, down, right)
                    int sum = findMaxSum(up, down, left, right, prefSum);

                    // update the max sum
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    return maxSum;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 10, 1, 3},
                               {-4, -1, 1, 7, -6}};

    cout << maxRectSum(mat) << endl;
    return 0;
}