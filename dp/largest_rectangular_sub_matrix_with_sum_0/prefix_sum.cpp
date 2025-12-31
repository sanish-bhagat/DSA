#include <bits/stdc++.h>
using namespace std;

int maxZeroSumSubarray(vector<int> &arr)
{
    int prefSum = 0, maxLength = 0;

    // hash map to store the first index of each prefix sum
    unordered_map<int, int> mp;

    // iterate through the temp[] to find the subarray with 0-sum
    for (int i = 0; i < arr.size(); i++)
    {
        prefSum += arr[i];

        // founded a subarray with 0-sum -> store the length of the submatrix
        if (prefSum == 0)
            maxLength = i + 1;

        // if this prefSum repeats, pick the maxLength
        if (mp.find(prefSum) != mp.end())
            maxLength = max(maxLength, i - mp[prefSum]);

        // store the index of first occurrence of prefsum
        else
            mp[prefSum] = i;
    }

    // return the max length of the 0-sum submatrix -> this will act as a width of the 0-sum submatrix
    return maxLength;
}

//! TC is O(n ^ 3)
//! SC is O(n)

int zeroSumSubmat(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();
    int maxArea = 0;

    // iterate through rows
    for (int i = 0; i < r; i++)
    {
        // store the column-wise cummulative sum of the matrix
        vector<int> temp(c, 0);

        for (int j = i; j < r; j++)
        {
            // accumulate column-wise sum for rows b/w i and j
            for (int k = 0; k < c; k++)
                temp[k] += mat[j][k];

            // length of the largest 0-sum sub-matrix
            int len = maxZeroSumSubarray(temp);

            // calculate the maxArea of the 0-sum sub-matrix
            maxArea = max(maxArea, (j - i + 1) * len);
        }
    }

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