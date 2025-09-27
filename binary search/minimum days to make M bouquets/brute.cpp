#include <bits/stdc++.h>
using namespace std;

// TC is O(N *  (max - min + 1))

bool possible(int arr[], int n, int day, int m, int k)
{
    int cnt = 0;
    int noOfB = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int minimumDays(int arr[], int n, int m, int k)
{
    long long val = m * 1LL * k * 1LL;
    if (val > n)
        return -1;
    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, n, i, m, k))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, m, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the no. of bouquets: ";
    cin >> m;

    cout << "Enter the no. of flowers in one bouquet: ";
    cin >> k;

    cout << minimumDays(arr, n, m, k);
}