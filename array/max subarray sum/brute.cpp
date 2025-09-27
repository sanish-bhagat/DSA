#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N*N)
// SC is O(1)

int maxSubArraySum(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
                maxi = max(maxi, sum);
            }
        }
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

    cout << maxSubArraySum(arr, n);
}