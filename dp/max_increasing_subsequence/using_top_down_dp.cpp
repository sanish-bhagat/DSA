#include <bits/stdc++.h>
using namespace std;

int maxSumRec(vector<int> &arr, int i, int j, vector<vector<int>> &memo)
{
    // base case, out of bound index -> return 0
    if (i == arr.size() + 1)
        return 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    // pick the max by including or excluding the curr element from the curr subsequence
    if (j == 0 || arr[i - 1] > arr[j - 1])
        return memo[i][j] = max(arr[i - 1] + maxSumRec(arr, i + 1, i, memo), maxSumRec(arr, i + 1, j, memo));

    // cannot include the curr element in the curr subsequence so move to next next element, as
    // a[i] <= a[j] -> voilates the subsequence property
    return memo[i][j] = maxSumRec(arr, i + 1, j, memo);
}

int maxSumIS(vector<int> &arr)
{
    int n = arr.size();

    // 2d memo[][] to store the computations during recursive calls
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    return maxSumRec(arr, 1, 0, memo);
}

int main()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);
}