#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * sum)
//! SC is O(sum)

int totalWays(int target, vector<int> &arr)
{
    int n = arr.size();

    // total sum of the arr[] elements
    int totalSum = 0;
    for (int x : arr)
        totalSum += x;

    // 1d[] to keep track of previous and curr states
    vector<int> prev(2 * totalSum + 1, 0);
    vector<int> curr;

    // 1 possible way to get the totalSum, starting from idx 0
    prev[totalSum] = 1;

    // traverse through every elements
    for (int i = 1; i <= n; i++)
    {
        curr.assign(2 * totalSum + 1, 0);

        // process for every sum
        for (int sum = 0; sum <= 2 * totalSum; sum++)
        {
            // add curr element
            if (sum + arr[i - 1] <= 2 * totalSum)
                curr[sum + arr[i - 1]] += prev[sum];

            // subtract curr element
            if (sum - arr[i - 1] >= 0)
                curr[sum - arr[i - 1]] += prev[sum];
        }

        // update the states
        prev = curr;
    }

    // return the total ways to achieve target
    return prev[target + totalSum];
}

int main()
{
    int target = 3;
    vector<int> arr = {1, 1, 1, 1, 1};

    cout << totalWays(target, arr);
}