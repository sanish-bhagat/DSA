#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int lis(vector<int> &arr)
{
    int n = arr.size();

    // 1d dp[] -> every element is an LIS of length 1
    vector<int> dp(n, 1);

    int res = 1;

    // itertively compute the values
    for (int i = 1; i < n; i++)
    {
        // pick the smaller elements in the left of i in the sequence
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
                dp[i] = max(dp[i], dp[prev] + 1);
        }

        // pick the max length of LIS
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lis(arr);
    return 0;
}