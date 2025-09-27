#include <bits/stdc++.h>
using namespace std;

bool helper(int idx, int bucketNum, int bucketSum, int reqSum, int k, vector<int> &arr, vector<int> &taken)
{
    // basecase: all subsets are formed with equal sum
    if (bucketNum == k)
        return true;

    // curr subset have reached the reqSum, create the next bucket
    if (bucketSum == reqSum)
        return helper(0, bucketNum + 1, 0, reqSum, k, arr, taken);

    // try to fill the curr bucket, traverse all the arr[] elements
    for (int i = idx; i < arr.size(); i++)
    {
        // if already visited or including the curr element will result in greater sum then req, just leave it
        if (taken[i] == 1 || bucketSum + arr[i] > reqSum)
            continue;

        // include the curr element
        taken[i] = 1;
        if (helper(i + 1, bucketNum, bucketSum + arr[i], reqSum, k, arr, taken))
            return true;

        // backtrack: unmark the curr element
        taken[i] = 0;
    }

    return false;
}

//! TC is O(k * (2 ^ n))
//! SC is O(n)

bool isKPartitionPossible(vector<int> &arr, int k)
{
    int n = arr.size();

    // total sum
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // partition not possible
    if (n < k || sum % k != 0)
        return false;

    // req sum for every subset
    int reqSum = sum / k;

    // keep track of visited elements
    vector<int> taken(n, 0);

    // sort in decreasing order
    sort(arr.rbegin(), arr.rend());

    return helper(0, 0, 0, reqSum, k, arr, taken);
}

int main()
{
    vector<int> arr = {2, 1, 4, 5, 3, 3};
    int k = 3;

    if (isKPartitionPossible(arr, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}