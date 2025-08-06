#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(k)

int kthSmallest(int arr[], int n, int k)
{
    // create a max heap
    priority_queue<int> pq;

    // traverse the unsorted array
    for (int i = 0; i < n; i++)
    {
        // push the curr element into max-heap
        pq.push(arr[i]);

        // if size of the max heap > k then pop the top element of the max-heap
        if (pq.size() > k)
            pq.pop();
    }

    // after traversing the array the top of the max-heap will be the kth smallest element
    return pq.top();
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int N = sizeof(arr) / sizeof(arr[0]), K = 2;

    // Function call
    cout << "K'th smallest element is "
         << kthSmallest(arr, N, K);
    return 0;
}