#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &arr)
{
    int n = arr.size();

    // total sum of the arr[] elements
    int currSum = 0;
    for (int x : arr)
        currSum += x;

    // intial configuration rotation value
    int currVal = 0;
    for (int i = 0; i < n; i++)
        currVal += i * arr[i];

    int res = currVal;

    // compute values for other iterations
    for (int i = 1; i < n; i++)
    {
        // compute next value using previous
        int nextVal = currVal - (currSum - arr[i - 1]) + arr[i - 1] * (n - 1);

        // update the curr value
        currVal = nextVal;

        // update the res
        res = max(res, nextVal);
    }

    return res;
}

int main()
{
    vector<int> arr = {3, 1, 2, 8};
    cout << maxSum(arr);
}