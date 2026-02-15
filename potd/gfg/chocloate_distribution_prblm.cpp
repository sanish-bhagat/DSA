#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int findMinDiff(vector<int> &arr, int m)
{
    // sort the given arr in increasing order
    sort(arr.begin(), arr.end());

    int minDiff = INT_MAX;

    // traverse through the arr and calculate the minDiff of window m
    for (int i = 0; i + m - 1 < arr.size(); i++)
    {
        // diff b/w max and min in curr window
        int diff = arr[i + m - 1] - arr[i];

        // minimize the diff
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}

int main()
{
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    cout << findMinDiff(arr, m);
    return 0;
}