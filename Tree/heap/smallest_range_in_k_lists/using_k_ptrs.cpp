#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k * k)
//! SC is O(k)

vector<int> findSmallestRange(vector<vector<int>> &arr)
{
    int k = arr.size();
    int n = arr[0].size();

    // ptrs to track the elements of each k rows
    vector<int> ptr(k, 0);

    int minRange = INT_MAX;
    int start = -1, end = -1;

    while (true)
    {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minRow = -1;

        // traverse all k rows to get the min and max elements
        for (int i = 0; i < k; i++)
        {
            if (ptr[i] == n)
                return {start, end};

            // min element and its corresponding row
            if (arr[i][ptr[i]] < minVal)
            {
                minVal = arr[i][ptr[i]];
                minRow = i;
            }

            // max element
            if (arr[i][ptr[i]] > maxVal)
                maxVal = arr[i][ptr[i]];
        }

        // update result range if smaller range is found
        if (maxVal - minVal < minRange)
        {
            minRange = maxVal - minVal;
            start = minVal;
            end = maxVal;
        }

        // move the ptr to row with min value
        ptr[minRow]++;
    }

    return {start, end};
}

int main()
{

    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};

    vector<int> res = findSmallestRange(arr);

    cout << res[0] << " " << res[1];

    return 0;
}