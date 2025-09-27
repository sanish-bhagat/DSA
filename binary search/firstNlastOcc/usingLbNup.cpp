#include <bits/stdc++.h>
using namespace std;

// TC is 2 * O(log N)  having base 2
// SC is O(1)

int lowerBound(int arr[], int n, int target)
{
    int low = 0, high = n - 1, ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
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

pair<int, int> Search(int arr[], int n, int target)
{
    int lb = lowerBound(arr, n, target);

    if (lb == n || arr[lb] != target)
    {
        return {-1, -1};
    }

    return {lb, upperBound(arr, n, target) - 1};
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

    pair<int, int> res = Search(arr, n, target);

    cout << res.first << "," << res.second << endl;
}