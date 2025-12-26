#include <bits/stdc++.h>
using namespace std;

int minMultiRec(int i, int j, vector<int> &arr, vector<vector<int>> &memo)
{
    // base case: only one matrix left
    if (i + 1 == j)
        return 0;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = INT_MAX;

    // Place the first bracket at different
    // positions or k and for every placed
    // first bracket, recursively compute
    // minimum cost for remaining brackets
    // (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultiRec(i, k, arr, memo) + minMultiRec(k, j, arr, memo) + arr[i] * arr[j] * arr[k];

        res = min(res, curr);
    }

    return res;
}

//! TC is O(n ^ 3)
//! SC is O(n * n)

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    // 2d memo[] to store recursive call values
    vector<vector<int>> memo(n, vector<int>(n, -1));

    // recursively explore all the combinations
    return minMultiRec(0, n - 1, arr, memo);
}

int main()
{

    vector<int> arr = {2, 1, 3, 4};
    cout << matrixMultiplication(arr);
    return 0;
}