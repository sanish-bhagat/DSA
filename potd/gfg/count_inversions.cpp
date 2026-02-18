#include <bits/stdc++.h>
using namespace std;

int countAndMerge(vector<int> &arr, int low, int mid, int high)
{
    // no. of elements in each half
    int n1 = mid - low + 1, n2 = high - mid;

    // store the elements of both the halves, respectively
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + low];

    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // count no. of inversions
    int res = 0;
    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        // left element is smaller than right half -> no inversion
        if (left[i] <= right[j])
            arr[k++] = left[i++];

        // right element is smaller, then total of (n1 - i) elements in
        // left are greater than right, since the left[] is sorted
        else
        {
            res += (n1 - i);
            arr[k++] = right[j++];
        }
    }

    // merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

int countInv(vector<int> &arr, int low, int high)
{
    int res = 0;

    if (low < high)
    {
        int mid = low + (high - low) / 2;

        // recusively count inversions in the left and right half
        res += countInv(arr, low, mid);
        res += countInv(arr, mid + 1, high);

        // count inversion such that greater element is at the left half
        // and smaller is at the right half
        res += countAndMerge(arr, low, mid, high);
    }

    return res;
}

//! TC is O(n * logn)
//! SC is O(n)

int inversionCount(vector<int> &arr)
{
    int n = arr.size();

    // use merge step of merge sort to count the inversions
    return countInv(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << inversionCount(arr);
}