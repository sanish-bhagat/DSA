#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSubarraySum(vector<int> &arr, int k)
{
    int n = arr.size();

    // stores the sum of every window(of size k)
    int windowSum = 0;

    // sum of 1st window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    // traverse the other windows from(k...n)
    for (int i = k; i < n; i++)
    {
        // add the new element in the window sum and remove the first element from the previous window
        windowSum += arr[i] - arr[i - k];

        // update the maxSum
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxSubarraySum(arr, k) << endl;
    return 0;
}