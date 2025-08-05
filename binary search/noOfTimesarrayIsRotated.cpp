#include <bits/stdc++.h>
using namespace std;

int noOfTimesArrayIsRotated(int arr[], int n)
{
    int index = -1, low = 0, high = n - 1, ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            { 
                index = low;
                ans = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {

            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
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

    cout << noOfTimesArrayIsRotated(arr, n);
}