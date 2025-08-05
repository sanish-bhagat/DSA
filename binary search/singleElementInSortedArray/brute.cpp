#include <bits/stdc++.h>
using namespace std;

//TC is O(N)

int singleElement(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        else if (i == n - 1)
        {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else
        {
            if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
                return arr[i];
        }
    }
    return -1;
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