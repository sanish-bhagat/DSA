#include <bits/stdc++.h>
using namespace std;

// TC is O(N)
// SC is O(1)

int maxProductSubarray(int arr[], int n)
{
    int maxi = INT_MIN, leftToRight = 1, rightToLeft = 1;

    for (int i = 0; i < n; i++)
    {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;

        leftToRight *= arr[i];
        rightToLeft *= arr[n - i - 1];

        maxi = max(maxi, max(leftToRight, rightToLeft));
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