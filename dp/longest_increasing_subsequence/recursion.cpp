#include <bits/stdc++.h>
using namespace std;

int lisRec(vector<int> &arr, int idx)
{
    // base case
    if (idx == 0)
        return 1;

    int mx = 1;

    // check for smaller elements in left from arr[idx]
    for (int prev = 0; prev < idx; prev++)
        if (arr[prev] < arr[idx])
            mx = max(mx, lisRec(arr, prev) + 1);

    return mx;
}

//! TC is O(2 ^ n)
//! SC is O(n)

int lis(vector<int> &arr)
{
    int n = arr.size();

    int res = 1;

    // for every i check for smaller elements at its left
    for (int i = 1; i < n; i++)
        res = max(res, lisRec(arr, i));

    return res;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lis(arr);
    return 0;
}