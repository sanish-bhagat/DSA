#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int MaxSumDifference(int a[], int n)
{
    vector<int> helper;

    // sort the arr[] to get the elements in increasing order
    sort(a, a + n);

    // build a helper[], where we will have the smallest element and then the largest element, alternatelly
    for (int i = 0; i < n / 2; i++)
    {
        helper.push_back(a[i]);
        helper.push_back(a[n - i - 1]);
    }

    // if size of the arr[] is odd, push the middle element of the arr[] in the last of the helper[]
    if (n % 2 != 0)
        helper.push_back(a[n / 2]);

    int maxSum = 0;

    // find the max sum
    for (int i = 0; i < n - 1; i++)
    {
        maxSum += abs(helper[i] - helper[i + 1]);
    }

    // abs difference between last and the first element of the arr[]
    maxSum += abs(helper[n - 1] - helper[0]);

    return maxSum;
}

int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << MaxSumDifference(a, n) << endl;
}