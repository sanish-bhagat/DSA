#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxDiffSubArrays(vector<int> &arr)
{
    int n = arr.size();

    // keep track of min and max sum subarrays ending at the curr index from both sides
    vector<int> leftMin(n), leftMax(n), rightMin(n), rightMax(n);

    // left max
    int curr = arr[0];
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = max(arr[i], curr + arr[i]);
        leftMax[i] = max(leftMax[i - 1], curr);
    }

    // left min
    curr = arr[0];
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = min(arr[i], curr + arr[i]);
        leftMin[i] = min(leftMin[i - 1], curr);
    }

    // right max
    curr = arr[n - 1];
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        curr = max(arr[i], curr + arr[i]);
        rightMax[i] = max(rightMax[i + 1], curr);
    }

    // right min
    curr = arr[n - 1];
    rightMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        curr = min(arr[i], curr + arr[i]);
        rightMin[i] = min(rightMin[i + 1], curr);
    }

    int ans = 0;

    // find the max abs sum of non-overlapping subarray
    for (int i = 0; i < n - 1; i++)
    {
        int diff1 = abs(leftMax[i] - rightMin[i + 1]);
        int diff2 = abs(leftMin[i] - rightMax[i + 1]);

        ans = max({ans, diff1, diff2});
    }

    return ans;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << maxDiffSubArrays(arr);
}