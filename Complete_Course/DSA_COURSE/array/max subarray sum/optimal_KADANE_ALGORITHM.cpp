#include <bits/stdc++.h>
using namespace std;

// TC is O(N)
// SC is O(1)

int ansStart = -1;
int ansEnd = -1;

int maxSubarraySum(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }
    return maxi;
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

    cout << "The max sum of the subarray is : " << maxSubarraySum(arr, n) << endl;

    cout << "The subarray is : ";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
}