#include <bits/stdc++.h>
using namespace std;

// TC is 2 * O(log N)  base 2

int firstOcc(int arr[], int n, int target)
{
    int low = 0, high = n - 1, first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1; // as we have to find the first occ
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOcc(int arr[], int n, int target)
{
    int low = 0, high = n - 1, last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1; // as we have to find the last occ
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> search(int arr[], int n, int target)
{
    int first = firstOcc(arr, n, target);

    if (first == -1)
        return {-1, -1};

    int last = lastOcc(arr, n, target);

    return {first, last};
}

int totalOcc(int arr[], int n, int target)
{

    pair<int, int> ans = search(arr, n, target);

    if (ans.first == -1)
        return 0;

    return ans.second - ans.first + 1;
}

int main()
{
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> target;

    cout << totalOcc(arr, n, target);
}