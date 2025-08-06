#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * logk)
//! SC is O(k)

int kthLargest(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    prefixSum[1] = arr[0];

    // generate the prefix sum, total sum of first i elements
    for (int i = 2; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // traverse the prefixSum[] position wise, and calculate the subarray sum
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // calculate the subarray sum
            int x = prefixSum[j] - prefixSum[i];

            // if size is less than k, then push the subarray sum
            if (pq.size() < k)
                pq.push(x);

            // if curr sum is greater than the pq.top() then pop the top and push the curr sum
            else
            {
                if (pq.top() < x)
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    // return the kth largest subarray sum, i.e top of the min-heap
    return pq.top();
}

int main()
{
    vector<int> arr = {20, -5, -1};
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}