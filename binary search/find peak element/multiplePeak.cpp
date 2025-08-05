#include <bits/stdc++.h>
using namespace std;

//returning any peak element

int findPeakElement(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    int low = 0, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;   //increasing slope  
        }
        else if (arr[mid] > arr[mid + 1])
        {
            high = mid - 1;   //decreasing slope
        } else {
            low = mid + 1;
        }
    }
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

    cout << findPeakElement(arr, n);
}