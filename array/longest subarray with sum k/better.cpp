#include <bits/stdc++.h>
using namespace std;

// *it is the optimal solution if the array contains negative,zero and positive no.
// time complexity for worst case if unordered map is used is O(N^2) and for best case is O(N*1)
// time complexity for ordered map is O(N*logN)
// space complexity is O(N)

int longestSubarray(int arr[], int n, int m)
{
    map<int, int> mpp;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == m)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - m;

        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
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