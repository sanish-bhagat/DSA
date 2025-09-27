#include <bits/stdc++.h>
using namespace std;

// TC is O( n /2 * n /2 ) + O(n * n / 2)
// SC is O(1) i.e no extra space is used

const int MAX_SIZE = 100;

void display(int arr[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(int arr[][100], int n)
{

    // transpose
    // O(n / 2 * n / 2)

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reverse
    // O(n * n / 2)

    for (int i = 0; i < n; i++)
    {
        reverseArray(arr[i], n);
    }

    display(arr, n);
}

int main()
{
    int n;
    cout << "Enter the row/column of the array : ";
    cin >> n;

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "ENter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;

    rotate(arr, n);
}