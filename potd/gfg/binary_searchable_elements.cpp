#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(logn)

int dfs(int l, int r, vector<int> &arr, int low, int high)
{
    // base case
    if (l > r)
        return 0;

    int ans = 0;

    int mid = l + (r - l) / 2;

    // valid searchable element
    if (low < arr[mid] && arr[mid] < high)
        ans++;

    // recurse for left and right subarray
    int left = dfs(l, mid - 1, arr, low, min(arr[mid], high));
    int right = dfs(mid + 1, r, arr, max(arr[mid], low), high);

    // return the total count
    return ans + left + right;
}

int binarySearchable(vector<int> &arr)
{
    int n = arr.size();

    // recurse starting with the intial search range(-INF...INF)
    return dfs(0, n - 1, arr, INT_MIN, INT_MAX);
}

int main()
{
    vector<int> arr = {1, 3, 2};
    cout << binarySearchable(arr);
}