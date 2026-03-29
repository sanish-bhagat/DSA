#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * totalSum)
//! SC is O(n)

int countPartitions(vector<int> &arr, int diff)
{
    // total sum of the given arr[]
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // target is not even or total sum < diff -> cannot perform partition
    if ((sum + diff) % 2 != 0 || sum < diff)
        return 0;

    // target we have to look for
    int target = (sum + diff) / 2;

    int n = arr.size();

    // 1d dp[] -> stores values of previous row
    vector<int> dp(target + 1, 0);

    // 1 way to make sum 0
    dp[0] = 1;

    // traverse through elements from left to right
    for (int i = 0; i < n; i++)
    {
        // traverse from right to left to avoid reuse of same element
        for (int j = target; j >= arr[i]; j--)
            dp[j] += dp[j - arr[i]];
    }

    // return the total no. of valid partitions with given diff
    return dp[target];
}

int main()
{
    vector<int> arr = {5, 2, 6, 4};
    int diff = 3;
    cout << countPartitions(arr, diff);
    return 0;
}