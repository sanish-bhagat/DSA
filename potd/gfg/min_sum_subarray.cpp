#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int minSubarraySum(vector<int> &arr)
{
    // kadane's algo
    int currSum = arr[0], minSum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        // include the curr element or start a new subarray
        currSum = min(arr[i], currSum + arr[i]);

        // keep track of the min sum subarray
        minSum = min(minSum, currSum);
    }

    return minSum;
}

int main()
{
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};

    cout << minSubarraySum(arr);
}