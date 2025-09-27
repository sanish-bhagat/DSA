#include <bits/stdc++.h>
using namespace std;

// in coding rounds use stl function upper_bound

int upperBound(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
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
    cout << "Enter the no. to be searched: ";
    cin >> target;

    cout << upperBound(arr, n, target);
}
