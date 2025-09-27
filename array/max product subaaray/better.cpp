#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)
// SC is O(1)

int maxProductSubarray(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int pro = 1;
        for (int j = i; j < n; j++)
        {
            pro *= arr[j];
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