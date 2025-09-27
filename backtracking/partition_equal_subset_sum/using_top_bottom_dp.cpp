#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int n, vector<int> &arr, int sum, vector<vector<int>> &memo)
{
    // base case: find the subset with desired sum
    if (sum == 0)
        return true;

    // base case: no subset found
    if (n == 0)
        return false;

    // if subproblem already computed, return the computed result
    if (memo[n - 1][sum] != -1)
        return memo[n - 1][sum];

    // current element is greater than the sum, ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(n - 1, arr, sum, memo);

    // subproblems, if any one is obtained:
    // 1- if sum can be obtained by excluding curr element or
    // 2- if sum can be obtained by including curr element
    return memo[n - 1][sum] = isSubsetSum(n - 1, arr, sum, memo) ||
                              isSubsetSum(n - 1, arr, sum - arr[n - 1], memo);
}

//! TC isw O(n * sum)
//! SC is O(n * sum)

bool equalPartition(vector<int> &arr)
{
    int n = arr.size();

    // sum of the arr[]
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // dp table
    vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));

    // sum is odd, arr[] cannot be partitioned in equal sum
    if (sum % 2 != 0)
        return false;

    // find subset with subsetSum = sum/2
    return isSubsetSum(n, arr, sum / 2, memo);
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    if (equalPartition(arr))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}