#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void mergeTwoParts(vector<int> &arr)
{
    int n = arr.size();

    int pIdx = -1;

    // find the break point
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            pIdx = i + 1;
            break;
        }
    }

    // arr is already sorted
    if (pIdx == -1)
        return;

    int i = 0, j = pIdx;

    vector<int> temp(n);
    int k = 0;

    // using the idea of merge sort
    while (i < pIdx && j < n)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
    }

    // copy the remaining element's if present
    while (i < pIdx)
        temp[k++] = arr[i++];

    while (j < n)
        temp[k++] = arr[j++];

    // copy to the original arr
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main()
{
    vector<int> arr = {2, 3, 8, -1, 7, 10};
    int n = arr.size();
    mergeTwoParts(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}