#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int maxAmount(int i, int j, vector<int> &arr, vector<vector<int>> &memo)
{
    // base case: no elements left to pick
    if (i > j)
        return 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    // either pick the first element
    int takeFirst = arr[i] + min(maxAmount(i + 2, j, arr, memo), maxAmount(i + 1, j - 1, arr, memo));

    // or pick the last element
    int takeLast = arr[j] + min(maxAmount(i, j - 2, arr, memo), maxAmount(i + 1, j - 1, arr, memo));

    // pcik the max one
    return memo[i][j] = max(takeFirst, takeLast);
}

int maximumAmount(vector<int> &arr)
{
    int n = arr.size();

    // 2d memo[]
    vector<vector<int>> memo(n, vector<int>(n, -1));

    // recursively explore the given[]
    return maxAmount(0, n - 1, arr, memo);
}

int main()
{

    vector<int> arr = {5, 3, 7, 10};
    int res = maximumAmount(arr);
    cout << res << endl;

    return 0;
}