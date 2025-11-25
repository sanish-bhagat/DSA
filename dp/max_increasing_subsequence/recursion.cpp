#include <bits/stdc++.h>
using namespace std;

int maxSumRec(vector<int> &arr, int i, int j)
{
    // base case, out of bound index -> return 0
    if (i == arr.size() + 1)
        return 0;

    // pick the max by including or excluding the curr element from the curr subsequence
    if (j == 0 || arr[i - 1] > arr[j - 1])
        return max(arr[i - 1] + maxSumRec(arr, i + 1, i), maxSumRec(arr, i + 1, j));

    // cannot include the curr element in the curr subsequence so move to next next element, as
    // a[i] <= a[j] -> voilates the subsequence property
    return maxSumRec(arr, i + 1, j);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int maxSumIS(vector<int> &arr)
{
    return maxSumRec(arr, 1, 0);
}

int main()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);
}