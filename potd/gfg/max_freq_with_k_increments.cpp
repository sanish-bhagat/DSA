#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int maxFrequency(vector<int> &arr, int k)
{
    // sort the given arr[]
    sort(arr.begin(), arr.end());

    long long windowSum = 0;
    int left = 0, res = 1;

    // sliding window technique
    for (int right = 0; right < arr.size(); right++)
    {
        // include the curr element
        windowSum += arr[right];

        // no. of operations required to increase every element to arr[right] ->
        // operations = arr[right] * windowLength - windowSum
        // operations required > k -> shrink the window
        while (1LL * arr[right] * (right - left + 1) - windowSum > k)
        {
            arr[left];
            left++;
        }

        // keep track of the max freq of any element after performing operations
        res = max(res, right - left + 1);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 2, 4};
    int k = 4;
    cout << maxFrequency(arr, k) << '\n';

    return 0;
}