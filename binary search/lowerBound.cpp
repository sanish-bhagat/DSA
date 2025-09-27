#include <bits/stdc++.h>
using namespace std;

// in coding rounds just use the in-built function => lower_bound(arr.begin(),arr.end(),target - arr.begin()) {if vector is given}
// for array use arr,arr + n in place of begin and end

int lowerBound(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // maybe an answer
        if (arr[mid] >= target)
        {
            ans = mid;

            // look for more small index on left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look for right
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

    cout << lowerBound(arr, n, target);
}
