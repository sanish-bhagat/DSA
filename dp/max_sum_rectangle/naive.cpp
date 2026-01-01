#include <bits/stdc++.h>
using namespace std;

//! TC is O((n * m) ^ 3)
//! SC is O(1)

int maxRectSum(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();

    int maxSum = INT_MIN;

    // traverse the given matrix in a rectangular fashion
    for (int top = 0; top < r; top++)
    {
        for (int left = 0; left < c; left++)
        {
            for (int bottom = top; bottom < r; bottom++)
            {
                for (int right = left; right < c; right++)
                {
                    int sum = 0;

                    // compute the sum of the rectangle formed
                    for (int i = top; i <= bottom; i++)
                    {
                        for (int j = left; j <= right; j++)
                            sum += mat[i][j];
                    }

                    // pick the max sum rectangle
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