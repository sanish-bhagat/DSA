#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * sum)
//! SC is O(sum)

bool equalPartition(vector<int> &arr)
{
    int n = arr.size();

    // sum of arr[]
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // sum is odd, arr[] cannot be partitioned in equal sum
    if (sum % 2 != 0)
        return false;

    // target subset sum
    sum = sum / 2;

    vector<bool> prev(sum + 1, false), curr(sum + 1);

    // for empty subset, sum is 0, so fill with true
    prev[0] = true;

    // traverse in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            // current element is greater than the sum, ignore it
            if (j < arr[i - 1])
                curr[j] = prev[j];

            // include or exclude the curr element
            else
                curr[j] = prev[j] || prev[j - arr[i - 1]];
        }

        // curr becomes our prev for next row
        prev = curr;
    }

    // return the result, stored in prev[]
    return prev[sum];
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