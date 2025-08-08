#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N*N)

void twoSum(int arr[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; i < n; i++)
        {
            if (arr[i] + arr[j] == m)
            {
                cout << i << " " << j;
            }
        }
    }
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

    int m;
    cout << "Enter the sum: ";
    cin >> m;

    twoSum(arr, n, m);
}