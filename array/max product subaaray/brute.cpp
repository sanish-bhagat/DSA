#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N*N)
// SC is O(1)

int maxProductSubarray(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int pro = 1;
            for (int k = i; k <= j; k++)
            {
                pro *= arr[k];
            }
            maxi = max(maxi, pro);
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
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxProductSubarray(arr, n);
}