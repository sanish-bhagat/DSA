#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(k)

int kthLargest(int arr[], int n, int k)
{
    // create a min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // traverse the ar[]
    for (int i = 0; i < n; i++)
    {
        // push the curr element into min-heap
        pq.push(arr[i]);

        // if heap size > k then pop the top of the min-heap
        if (pq.size() > k)
            pq.pop();
    }

    // after traversing the arr[], the top of the min-heap will be the kth largest element
    return pq.top();
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int N = sizeof(arr) / sizeof(arr[0]), K = 2;

    // Function call
    cout << "K'th largest element is "
         << kthLargest(arr, N, K);
    return 0;
}