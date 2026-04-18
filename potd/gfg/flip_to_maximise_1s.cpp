#include <bits/stdc++.h>
using namespace std;

// max subarray sum using kadane's algo
int maxSubSum(vector<int> &arr)
{
    int sum = 0, maxSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // include curr element
        sum += arr[i];

        // pick the max one
        maxSum = max(maxSum, sum);

        // sum becomes -ve -> start a new subarray
        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

//! TC is O(n)
//! SC is O(1)

int maxOnes(vector<int> &arr)
{
    int oneCnt = 0;

    // keep track of one count
    // set 1 -> -1(since flipping it will decrease the count of 1's) and
    // 0 -> 1(since flipping it will increase the count of 1's)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            oneCnt++;
            arr[i] = -1;
        }

        else
            arr[i] = 1;
    }

    // max subarray sum of the modified arr[] to find the max possible gain in 1's
    int flippedOnes = maxSubSum(arr);

    // return total one's + flipped ones
    return oneCnt + flippedOnes;
}

int main()
{
    vector<int> arr = {1, 0, 0, 1, 0, 0, 1};
    cout << maxOnes(arr);
}