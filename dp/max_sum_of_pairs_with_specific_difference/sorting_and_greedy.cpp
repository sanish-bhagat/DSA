#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // sort the given array in increasing order
    sort(arr, arr + N);
    int sum = 0;

    // traverse from the last of the sorted array(from the largest element)
    int i = N - 1;

    while (i > 0)
    {
        // include the curr pair if it is valid
        if (arr[i] - arr[i - 1] < K)
        {
            // include the pair sum in the result sum
            sum += arr[i] + arr[i - 1];

            // skip both the elements, as both of them have been included
            i -= 2;
        }

        // skip the largest element
        else
            i--;
    }

    // return the max sum of valid pairs
    return sum;
}

int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr) / sizeof(int);

    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}