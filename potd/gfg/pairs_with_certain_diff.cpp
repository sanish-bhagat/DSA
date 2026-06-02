#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int sumDiffPairs(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxSum = 0;

    // sort the arr[] in decreasing order
    // to ensure we traverse the larger pairs first
    sort(arr.begin(), arr.end());

    // traverse the sorted arr[] from end
    for (int i = n - 1; i > 0; i--)
    {
        // diff of arr[i] and arr[i-1] < k -> valid pair, include in the sum
        // else we move on to the next pair
        if (arr[i] - arr[i - 1] < k)
        {
            maxSum += arr[i];
            maxSum += arr[i - 1];

            // when a valid pair is found, we skip this pair
            --i;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {3, 5, 10, 15, 17, 12, 9};
    int k = 4;
    cout << sumDiffPairs(arr, k);
}