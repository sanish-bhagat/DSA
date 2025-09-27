#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &merged, int n, int i)
{
    if (i >= n)
        return;

    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && merged[l] > merged[max])
        max = l;

    if (r < n && merged[r] > merged[max])
        max = r;

    if (max != i)
    {
        swap(merged[max], merged[i]);
        maxHeapify(merged, n, max);
    }
}

void buildMaxHeap(vector<int> &merged, int n)
{
    // perform the max-heapify for the non-leaf nodes
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(merged, n, i);
}

//! TC is O(n + m)
//! SC is O(n + m)

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> merged(n + m, 0);

    // flatten the heaps if required, and then merge them
    for (int i = 0; i < n; i++)
        merged[i] = a[i];

    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];

    // using the merged array, build the max-heap
    buildMaxHeap(merged, n + m);
    return merged;
}

int main()
{
    // Sample Input
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size(), m = b.size();

    vector<int> merged = mergeHeaps(a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";
    return 0;
}