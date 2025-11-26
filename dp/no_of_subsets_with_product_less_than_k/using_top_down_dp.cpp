#include <bits/stdc++.h>
using namespace std;

int countSubsets(int i, int currProd, int k, vector<int> &arr, vector<vector<int>> &memo)
{
    int n = arr.size();

    // base case: all elements processed -> eturn 1 if the current product is less than or equal to k,
    // otherwise return 0
    if (i == n)
        return (currProd <= k);

    // already computed subproblem
    if (memo[i][currProd] != -1)
        return memo[i][currProd];

    // exclude the curr element
    int exclude = countSubsets(i + 1, currProd, k, arr, memo);

    int include = 0;

    // include the curr element if the product remains <= k
    if (arr[i] * currProd <= k)
        include = countSubsets(i + 1, arr[i] * currProd, k, arr, memo);

    // return the total no. of subsets including both cases
    return memo[i][currProd] = (include + exclude);
}

//! TC is O(n * k)
//! SC is O(n * k)

int numOfSubsets(vector<int> &arr, int k)
{
    int n = arr.size();

    // 2d memo[][] to store computed results during recursive calls
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    // return the total count of subsets, excluding the empty set{}
    return countSubsets(0, 1, k, arr, memo) - 1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << numOfSubsets(arr, k);
    return 0;
}