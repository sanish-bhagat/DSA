#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int smallestSumSubarr(vector<int> &arr)
{
    int n = arr.size();

    // initialise the sum variables
    int min_sum = arr[0], curr_sum = arr[0];

    // explore all the subarrays and pick the minimum one
    for (int i = 1; i < n; i++)
    {
        // either include the curr element in the subarray or
        // start a new subarray from the curr index
        curr_sum = min(arr[i], curr_sum + arr[i]);

        // pick the minimum from both of the cases
        min_sum = min(min_sum, curr_sum);
    }

    // return the minimum sum subarray
    return min_sum;
}

int main()
{
    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
    cout << smallestSumSubarr(arr);
    return 0;
}