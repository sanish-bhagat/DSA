#include <bits/stdc++.h>
using namespace std;

long long countAtMost(vector<int> &arr, int x)
{
    long long sum = 0, cnt = 0;
    int left = 0;

    // sliding window approach
    for (int right = 0; right < arr.size(); right++)
    {
        // include in the curr window
        sum += arr[right];

        // shrink the window
        while (sum > x && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        // include count of valid subarrays
        cnt += (right - left + 1);
    }

    return cnt;
}

//! TC is O(n)
//! SC is O(1)

long long countSubarray(int l, int r, vector<int> &arr)
{
    // no of valid subarrays will be the ones with sum having between r and l
    return countAtMost(arr, r) - countAtMost(arr, l - 1);
}

int main()
{
    vector<int> arr = {2, 3, 5, 8};
    int l = 4, r = 13;

    cout << countSubarray(l, r, arr);
}