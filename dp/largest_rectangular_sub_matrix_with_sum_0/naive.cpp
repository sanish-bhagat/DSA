#include <bits/stdc++.h>
using namespace std;

//! TC is O(R^3 * C^3)
//! SC is O(1)

int zeroSumSubmat(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();

    int maxArea = INT_MIN;

    // traverse the matrix[][] in rectangular fashion
    for (int top = 0; top < r; top++)
    {
        for (int bottom = top; bottom < r; bottom++)
        {
            for (int left = 0; left < c; left++)
            {
                for (int right = left; right < c; right++)
                {
                    // calculate the sum of the rectangular sub-matrix
                    int sum = 0;

                    for (int i = top; i <= bottom; i++)
                    {
                        for (int j = left; j <= right; j++)
                        {
                            sum += mat[i][j];
                        }
                    }

                    // if sum of the sub-matrix is zero -> then update the max area
                    if (sum == 0)
                    {
                        int area = (bottom - top + 1) * (right - left + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
    }

    // return the max area of the rectangular sub-matrix
    return maxArea;
}

int main()
{
    vector<vector<int>> mat = {{9, 7, 16, 5},
                               {1, -6, -7, 3},
                               {1, 8, 7, 9},
                               {7, -2, 0, 10}};
    cout << zeroSumSubmat(mat) << endl;
    return 0;
}