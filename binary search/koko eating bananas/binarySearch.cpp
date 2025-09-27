#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
    }
    return maxi;
}

int calculateTotalHours(int arr[], int n, int hourly)
{
    int totalHrs = 0;

    for (int i = 0; i < n; i++)
    {
        totalHrs += ceil((double)arr[i] / (double)hourly);
    }
    return totalHrs;
}

int minimumrateToEatBanana(int arr[], int n, int h)
{
    int low = 1, high = max(arr, n);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalHrs = calculateTotalHours(arr, n, mid);

        if (totalHrs <= h)
        {
            high = mid - 1;   //minimum value find krrna h
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, h;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the time limit: ";
    cin >> h;

    cout << minimumrateToEatBanana(arr, n, h);
}