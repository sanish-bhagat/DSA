#include <bits/stdc++.h>
using namespace std;

int minMultiRec(int i, int j, vector<int> &arr)
{
    // base case: only one matrix left
    if (i + 1 == j)
        return 0;

    int res = INT_MAX;

    // Place the first bracket at different
    // positions or k and for every placed
    // first bracket, recursively compute
    // minimum cost for remaining brackets
    // (or subproblems)
    for (int k = i + 1; k < j; k++)
    {
        int curr = minMultiRec(i, k, arr) + minMultiRec(k, j, arr) + arr[i] * arr[j] * arr[k];

        res = min(res, curr);
    }

    return res;
}

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    return minMultiRec(0, n - 1, arr);
}

int main()
{

    vector<int> arr = {2, 1, 3, 4};
    cout << matrixMultiplication(arr);
    return 0;
}