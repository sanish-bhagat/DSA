#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &arr)
{
    int rows = arr.size();
    int currSum = 0, maxSum = INT_MIN;

    // itertate through the temp[]
    for (int i = 0; i < rows; i++)
    {
        // include the curr element in the curr sum
        currSum += arr[i];

        // update the maxSum
        if (maxSum < currSum)
            maxSum = currSum;

        // currSum becomes negative -> reset it to 0
        if (currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

//! TC is O(n * m ^ 2)
//! SC is O(n)

int maxRectSum(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // temp[] to store sum of rows of fixed columns
    vector<int> temp(n, 0);

    int maxSum = INT_MIN;

    // traverse the columns
    for (int left = 0; left < m; left++)
    {
        // initialise the temp[] with 0
        for (int i = 0; i < n; i++)
            temp[i] = 0;

        for (int right = left; right < m; right++)
        {
            // calculate the cummulative sum for rows between columns(left and right)
            for (int row = 0; row < n; row++)
                temp[row] += mat[row][right];

            // find the max sum of the subarray for the curr column coundaries
            int sum = kadane(temp);

            // update the maxSum
            maxSum = max(maxSum, sum);
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