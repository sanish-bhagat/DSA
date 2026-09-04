#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxFruits(vector<int> &arr, int m)
{
    int n = arr.size();

    int sum = 0;

    // 1st window sum
    for (int i = 0; i < m; i++)
        sum += arr[i];

    int res = sum, left = 0;

    // traverse through the remaining circular arr[] elements
    for (int right = m; right < n + m; right++)
    {
        // remove the out of size window
        sum -= arr[left];

        // include the curr element
        sum += arr[right % n];

        // update res and move left ptr
        res = max(res, sum);
        left++;
    }

    return res;
}

int main()
{
    vector<int> arr = {7, 2, 1, 3, 4};
    int m = 2;

    cout << maxFruits(arr, m) << endl;

    return 0;
}