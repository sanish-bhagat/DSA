#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n);

    long long sum = 0;

    // Subtracting a1, a2, a3,....., a(n/2)-1, an/2 twice
    // and adding a(n/2)+1, a(n/2)+2, a(n/2)+3,....., an - 1, an twice.
    for (int i = 0; i < n / 2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }

    return sum;
}

int main()
{
    int arr[] = {4, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}