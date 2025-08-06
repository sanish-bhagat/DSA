#include <bits/stdc++.h>
using namespace std;

// TC is O(N)
// SC is O(1)
// MOORE'S VOTING ALGORITHM

int majorityElement(int arr[], int n)
{
    int count = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            count1++;
    }

    if (count1 > n / 2)
        return el;
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

    cout << majorityElement(arr, n);
}