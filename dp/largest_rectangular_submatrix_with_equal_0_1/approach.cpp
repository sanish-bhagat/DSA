#include <bits/stdc++.h>
using namespace std;

int maxZeroSumSubarray(vector<int> &arr)
{
    int prefSum = 0, maxLen = 0;

    // {sum: index}
    unordered_map<int, int> mp;

    // itertate through the elements of the cummulative sum[]
    for (int i = 0; i < arr.size(); i++)
    {
        prefSum += arr[i];

        if (prefSum == 0)
            maxLen = i + 1;

        // already exist -> pick the max length
        if (mp.find(prefSum) != mp.end())
            maxLen = max(maxLen, i - mp[prefSum]);

        // new sum -> assign the current index
        else
            mp[prefSum] = i;
    }

    // return the max length of the 0-sum submatrix -> behaves as the width used to calculate area
    return maxLen;
}

//! TC is O(r ^ 2 * c)
//! SC is O(c)

int largestEqualZeroOneSubmatrix(vector<vector<int>> &mat)
{
    int r = mat.size(), c = mat[0].size();

    int maxArea = INT_MIN;

    // mat[i][j] = 0 -> change it to -1
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 0)
                mat[i][j] = -1;
        }
    }

    // itertate through the given matrix
    for (int top = 0; top < r; top++)
    {
        // store column cummulative sum for every row
        vector<int> temp(c, 0);

        for (int bottom = top; bottom < r; bottom++)
        {
            for (int col = 0; col < c; col++)
                temp[col] += mat[bottom][col];

            // find the maxLength with 0-sum
            int len = maxZeroSumSubarray(temp);

            // pick the max area of the 0-sum submatrix
            maxArea = max(maxArea, (bottom - top + 1) * len);
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1}};

    cout << "Largest area with equal 0s and 1s: "
         << largestEqualZeroOneSubmatrix(mat) << endl;

    return 0;
}