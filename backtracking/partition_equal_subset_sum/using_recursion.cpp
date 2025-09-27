#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int n, vector<int> &arr, int sum)
{
    // base case: find the subset with desired sum
    if (sum == 0)
        return true;

    // base case: no subset found
    if (n == 0)
        return false;

    // current element is greater than the sum, ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(n - 1, arr, sum);

    // subproblems, if any one is obtained:
    // 1- if sum can be obtained by excluding curr element or
    // 2- if sum can be obtained by including curr element
    return isSubsetSum(n - 1, arr, sum) || isSubsetSum(n - 1, arr, sum - arr[n - 1]);
}

//! TC is O(2 ^ n)
//! SC is O(n)

bool equalPartition(vector<int> &arr)
{
    // sum of the arr[]
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // sum is odd, arr[] cannot be partitioned in equal sum
    if (sum % 2 != 0)
        return false;

    // find subset with subsetSum = sum/2
    return isSubsetSum(arr.size(), arr, sum / 2);
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