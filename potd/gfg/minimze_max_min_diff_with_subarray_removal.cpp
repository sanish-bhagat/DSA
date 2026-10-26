#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minDiff(int k, vector<int> &arr)
{
    int n = arr.size();

    // max and min values from each index to end
    vector<int> suffixMax(n), suffixMin(n);

    suffixMax[n - 1] = arr[n - 1];
    suffixMin[n - 1] = arr[n - 1];

    // build the suffix[] from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(arr[i], suffixMax[i + 1]);
        suffixMin[i] = min(arr[i], suffixMin[i + 1]);
    }

    // remove the prefix of size k
    int res = suffixMax[k] - suffixMin[k];

    // keep track of max and min prefix values
    int prefixMax = arr[0], prefixMin = arr[0];

    // remove a middle subarray of size k
    for (int i = 1; i < n - k; i++)
    {
        // curr max and min in the remaining subarray
        int currMax = max(prefixMax, suffixMax[i + k]);
        int currMin = min(prefixMin, suffixMin[i + k]);

        res = min(res, currMax - currMin);

        // update the prefix values
        prefixMax = max(prefixMax, arr[i]);
        prefixMin = min(prefixMin, arr[i]);
    }

    // remove the suffix of size k
    res = min(res, prefixMax - prefixMin);

    return res;
}

int main()
{
    vector<int> arr = {2, 3, 1, 4, 6, 7};
    int k = 3;

    cout << minDiff(k, arr) << endl;

    return 0;
}