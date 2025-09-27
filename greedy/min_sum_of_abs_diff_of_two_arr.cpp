#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

long long findMinSum(int a[], int b[], int n)
{
    // sort both the arr[]
    sort(a, a + n);
    sort(b, b + n);

    long long int sum = 0;

    // sum of the absolute differences
    for (int i = 0; i < n; i++)
        sum += abs(a[i] - b[i]);

    return sum;
}

int main()
{
    // Both a[] and b[] must be of same size.
    int a[] = {4, 1, 8, 7};
    int b[] = {2, 3, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%lld\n", findMinSum(a, b, n));
    return 0;
}