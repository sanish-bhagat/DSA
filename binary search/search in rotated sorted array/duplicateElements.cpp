#include <bits/stdc++.h>
using namespace std;

bool search(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue; // continue issliye use kiya h kyuki ho sakta h next element bhi duplicate ho issliye ye condition bar bar check hoga
        }

        if (arr[low] <= arr[mid])
        { // search in the left part of the array
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else
        { // search in the right part of the array
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
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

    int target;
    cout << "Enter the element to be searched: ";
    cin >> target;

    if (search(arr, n, target))
    {
        cout << "Element present";
    }
    else
    {
        cout << "Element not present";
    }
}