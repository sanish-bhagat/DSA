#include <bits/stdc++.h>
using namespace std;

int maxCircularSum(vector<int> &arr)
{
    // keep track of maxSum, minSum, totalSum of the given arr[]
    int maxSum = arr[0], minSum = arr[0], totalSum = 0;

    int currMin = 0, currMax = 0;

    // use kadane's algo for maxSum and reverse kadane's for minSum
    for (int x : arr)
    {
        // kadane's algo for maxSum
        currMax = max(x, currMax + x);
        maxSum = max(maxSum, currMax);

        // reverse kadane's algo for minSum
        currMin = min(x, currMin + x);
        minSum = min(minSum, currMin);

        // totalSum of the arr[]
        totalSum += x;
    }

    // all negative case
    if (maxSum < 0)
        return maxSum;

    // return the maxSum
    return max(maxSum, totalSum - minSum);
}

int main()
{
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << maxCircularSum(arr);
}