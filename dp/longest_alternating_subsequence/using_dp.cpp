#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(2 * n)

int LAS(int arr[], int n)
{
    // 2d dp[][] => initialized with value 1 -> each element alone is a valid las of length 1
    // dp[i][0] -> length of las ending at index i such that last element is greater than its previous element
    // dp[i][1] -> length of las ending at index i such that last element is smaller than its previous element
    vector<vector<int>> dp(n, vector<int>(2, 1));

    int res = 1;

    // compute values in bottom-up manner
    for (int i = 1; i < n; i++)
    {
        // consider all elements as previous of arr[i]
        for (int j = 0; j < i; j++)
        {
            // arr[i] is greater, then check with dp[j][1]
            if (arr[j] < arr[i] && dp[i][0] < dp[j][1] + 1)
                dp[i][0] = dp[j][1] + 1;

            // arr[i] is smaller, then check with dp[j][0]
            if (arr[j] > arr[i] && dp[i][1] < dp[j][0] + 1)
                dp[i][1] = dp[j][0] + 1;

            // update res with the max of both values at index i
            res = max({res, dp[i][0], dp[i][1]});
        }
    }

    // return the las
    return res;
}

int main()
{
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    cout << LAS(arr, n) << endl;
    return 0;
}