#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool isMaxHeap(vector<int> &arr)
{
    int n = arr.size();

    // traverse internal nodes
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        // curr node's left and right child node index
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // left child > curr node -> violates max heap property
        if (arr[i] < arr[left])
            return false;

        // right child > curr node -> violates max heap property
        if (right < n && arr[i] < arr[right])
            return false;
    }

    // arr[] is max heap
    return true;
}

int main()
{
    vector<int> arr = {30, 15, 10, 7, 12, 2};
    cout << isMaxHeap(arr);
}