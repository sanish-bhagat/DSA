#include <bits/stdc++.h>
using namespace std;

int findInd(int key, int i, int n, int k, int a[])
{
    int start, end, mid, ind = -1;

    // start from the next element of the key
    start = i + 1, end = n - 1;

    // traverse until no elements are left
    while (start <= end)
    {
        // find a mid index
        mid = start + (end - start) / 2;

        // if condition is satisfied
        if (a[mid] - key <= k)
        {
            // store the curr position and move start to mid + 1 to find out more minimal solutions if possible
            ind = mid;
            start = mid + 1;
        }

        // move the end ptr to the mid - 1 index
        else
            end = mid - 1;
    }

    // return the stored position
    return ind;
}

//! TC is O(n * logn)
//! SC is O(1)

int removals(int a[], int n, int k)
{
    int i, j, ans = n - 1;

    // sort the given arr[] in increasing order
    sort(a, a + n);

    // iteratively traverse through every element and find the min removals required
    for (i = 0; i < n; i++)
    {
        // find such a j for which (arr[j] - arr[i]) <= k
        j = findInd(a[i], i, n, k, a);

        // if such a j exists -> elements to be removed for this case are = n - (j - i + 1)
        if (j != -1)
            ans = min(ans, n - (j - i + 1));
    }

    return ans;
}

int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}