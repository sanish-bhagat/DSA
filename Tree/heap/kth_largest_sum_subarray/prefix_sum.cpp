#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * logn)
//! SC is O(n * n)

int kthLargest(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> sums;

    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;

    // store the prefix sum, total sum of first i elements
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];

    // calculate the subarray sum and store it in the sums[]
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sums.push_back(prefixSum[j] - prefixSum[i]);
        }
    }

    // sort the sums[] in descending order
    sort(sums.begin(), sums.end(), greater<int>());

    // return the kth largest subarray sum
    return sums[k - 1];
}

int main()
{
    vector<int> arr = {20, -5, -1};
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}