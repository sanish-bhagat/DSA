#include <iostream>
#include <queue>
using namespace std;

//! To find the smallest element we use max heap and
//! To find the largest element we use min heap

//! TC is O(n)
//! SC is O(k)
int kThSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    // step1 - make a max heap of first k elements
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step2 - for rest elements (k -> n - 1), if element < heap.top() then,
    // heap.pop() and heap.push(element)
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // ans is the top of the heap
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[5] = {7, 10, 4, 20, 15};

    cout << kThSmallest(arr, 5, 4);
}