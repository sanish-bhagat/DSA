#include <bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i + 1] < arr[i]))
        {
            return arr[i];
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