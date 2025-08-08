#include <bits/stdc++.h>
using namespace std;

int singleElement(int arr[], int n)
{
    int low = 1, high = n - 2; // overflow na hojaye issliye low = 1 and high = n - 2 liya h taaki left or right part of the low or high check ho paye

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        // we are in left part
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }

        // we are in right part
        else
        {
            high = mid - 1;
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
    cout << singleElement(arr, n);
}