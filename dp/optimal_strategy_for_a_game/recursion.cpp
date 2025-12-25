#include <bits/stdc++.h>
using namespace std;

int maxAmount(int i, int j, vector<int> &arr)
{
    // base case: no elements left to pick
    if (i > j)
        return 0;

    // either take the first element
    int takeFirst = arr[i] + min(maxAmount(i + 2, j, arr), maxAmount(i + 1, j - 1, arr));

    // or take the last element
    int takeLast = arr[j] + min(maxAmount(i, j - 2, arr), maxAmount(i + 1, j - 1, arr));

    // pick the max of both the choices
    return max(takeFirst, takeLast);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int maximumAmount(vector<int> &arr)
{
    int n = arr.size();

    // traverse the given[] recursively
    return maxAmount(0, n - 1, arr);
}

int main()
{

    vector<int> arr = {5, 3, 7, 10};
    int res = maximumAmount(arr);
    cout << res << endl;

    return 0;
}