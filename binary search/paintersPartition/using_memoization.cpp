#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * k)
//! SC is O(n * k)

int minimizeTime(int curr, int n, vector<int> &arr, int k, vector<vector<int>> &memo)
{

    // base case
    if (curr >= n)
        return 0;

    if (k == 0)
        return INT_MAX;

    if (memo[curr][k] != -1)
        return memo[curr][k];

    int res = INT_MAX;
    int currSum = 0;

    for (int i = curr; i < n; i++)
    {
        currSum += arr[i];

        int remTime = minimizeTime(i + 1, n, arr, k - 1, memo);
        int remaining = max(currSum, remTime);

        res = min(res, remaining);
    }

    return memo[curr][k] = res;
}

int minTime(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    return minimizeTime(0, n, arr, k, memo);
}

int main()
{
    vector<int> arr = {10, 10, 10, 10};
    int k = 2;
    int res = minTime(arr, k);
    cout << res << endl;

    return 0;
}