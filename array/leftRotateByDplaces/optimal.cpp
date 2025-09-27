#include <bits/stdc++.h>
using namespace std;

// time complexity is O(d) + O(n-d) + O(n) => O(2n)
// extra space used is O(1) because we have used the given array

void reverseArray(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    reverseArray(arr, 0, n - d - 1);
    reverseArray(arr, n - d, n - 1);
    reverseArray(arr, 0, n - 1);
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

    int d;
    cout << "Enter the no. of rotation: ";
    cin >> d;
    d = d % n;

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}