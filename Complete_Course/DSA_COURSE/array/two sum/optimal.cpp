#include <bits/stdc++.h>
using namespace std;

// time complexity is O(N) + O(N*logN)
// space complexity is O(1)
// optimal solution only if indexes are not needed

void twoSum(int arr[], int n, int m)
{
    int left = 0;
    int right = n - 1;
    sort(arr, arr + n);

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == m)
        {
            cout << "YES";
            break;
        }
        else if (sum < m)
            left++;
        else
            right--;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the sum : ";
    cin >> m;

    twoSum(arr, n, m);
}