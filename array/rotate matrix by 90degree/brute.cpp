#include <bits/stdc++.h>
using namespace std;

// TC is O(N*N)
// SC is O(N*N)

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

void rotate(int arr[][100], int n)
{
    int res[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - i - 1] = arr[i][j];
        }
    }

    display(res, n);
}

int main()
{
    int n;
    cout << "Enter the row/columns of the array: ";
    cin >> n;

    int arr[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the array: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    rotate(arr, n);
}