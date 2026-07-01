#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSumSubarray(vector<int> &arr)
{
    // noDel -> Maximum subarray sum ending at current index
    //         without deletion
    // oneDel -> Maximum subarray sum ending at current index
    //         with at most one deletion
    int noDel = arr[0], oneDel = 0;

    int ans = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        // either delete curr element or extend previous deleted subarray
        oneDel = max(noDel, arr[i] + oneDel);

        // either start a new subarray from the curr element or
        // extend the previous no deleted subarray
        noDel = max(arr[i], arr[i] + noDel);

        // pick the max of both the cases
        ans = max({ans, noDel, oneDel});
    }

    return ans;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxSumSubarray(arr);
}