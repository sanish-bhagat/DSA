#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(min(n, k))

int longestSubarrayDivK(vector<int> &arr, int k)
{
    int n = arr.size(), res = 0;

    // hashmap to store the start idx of prefixSum
    unordered_map<int, int> prefIdx;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // include the curr element in the sum
        sum = (sum + arr[i]) % k;

        // handle -ve sum case
        if (sum < 0)
            sum += k;

        // whole subarray is valid -> divisble by k
        if (sum == 0)
            res = i + 1;

        // update res
        if (prefIdx.count(sum))
            res = max(res, i - prefIdx[sum]);

        // include in the map if and only if its the first occurence of the prefixSum
        else
            prefIdx[sum] = i;
    }

    return res;
}

int main()
{
    vector<int> arr = {-2, 2, -5, 12, -11, -1, 7};
    int k = 3;

    cout << longestSubarrayDivK(arr, k);
}