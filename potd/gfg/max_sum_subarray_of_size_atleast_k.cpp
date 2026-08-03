#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSumWithK(int k, vector<int> &arr)
{
    int total = 0;

    // 1st window sum
    for (int i = 0; i < k; i++)
        total += arr[i];

    int maxSum = total;

    // prefix -> keeps track of prefix sum just before out k sized window
    // minPrefixSum -> keeps track of min prefix seen
    int prefix = 0, minPrefixSum = 0;

    for (int i = k; i < arr.size(); i++)
    {
        // include the curr element
        total += arr[i];

        prefix += arr[i - k];

        // pick the min prefix seen so far
        minPrefixSum = min(minPrefixSum, prefix);

        // max sum is total sum - the worst prefix seen so far
        maxSum = max(maxSum, total - minPrefixSum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {-4, -2, 1, -3};
    int k = 2;

    cout << maxSumWithK(k, arr);
}