#include <bits/stdc++.h>
using namespace std;

// * optimal solution if only array contains positive and zeros
// time complexity is O(2N)
// space complexity is O(1)

int longestSubarray(int arr[], int n, int m)
{
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > m)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == m)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the sum of the subarray: ";
    cin >> m;

    cout << longestSubarray(arr, n, m);
}