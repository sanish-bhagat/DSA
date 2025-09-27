#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n *logn)
//! SC is O(n * n)

int kthLargest(vector<int> &arr, int k)
{
    vector<int> sums;

    // find the sum of all subarrays and store them
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            sums.push_back(sum);
        }
    }

    // sort the sums[] in descending order
    sort(sums.begin(), sums.end(), greater<int>());

    // return the kth largest sum
    return sums[k - 1];
}

int main()
{
    vector<int> arr = {20, -5, -1};
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}