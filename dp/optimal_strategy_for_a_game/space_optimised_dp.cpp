#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int maximumAmount(vector<int> &arr)
{
    int n = arr.size();

    // 1d dp[]
    vector<int> dp(n, 0);
    int sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // Calculating the sum of all the elements
        sum += arr[i];

        for (int j = i; j < n; j++)
        {
            // If there is only one element
            if (i == j)
                dp[j] = arr[j];

            // Calculating the dp states using the recurrence relation
            else
                dp[j] = max(arr[i] - dp[j], arr[j] - dp[j - 1]);
        }
    }

    // return the final result
    return (sum + dp[n - 1]) / 2;
}

int main()
{

    vector<int> arr = {5, 3, 7, 10};
    cout << maximumAmount(arr);

    return 0;
}