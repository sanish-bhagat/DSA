#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int MaxSumDifference(int a[], int n)
{
    // sort the arr[]
    sort(a, a + n);

    int sum = 0;

    // flag to track the updation of ptrs alternatively
    bool off = true;

    // two pointe approach
    int i = 0, j = n - 1;

    // calculate sum of abs difference
    while (i < j)
    {
        sum += abs(a[i] - a[j]);

        // alternatively update the ptrs
        if (!off)
            j--;

        else
            i++;

        // update the flag for next iteration
        off = !off;
    }

    // abs difference of the middle element and the first element
    sum += abs(a[i] - a[0]);

    // return the max sum
    return sum;
}

int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << MaxSumDifference(a, n) << endl;
}