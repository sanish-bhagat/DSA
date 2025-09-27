#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O9n

vector<double> getMedian(vector<int> &arr)
{
    // max-heap to store the smaller half of elements(left half)
    priority_queue<int> maxHeap;

    // min heap to store the greater half of elements(right half)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<double> res;

    // traverse the arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // insert the element into the max-heap
        maxHeap.push(arr[i]);

        // then push top of max-heap into min-heap to maintain the order
        int temp = maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);

        // balance heap if min-heap has more elements
        if (minHeap.size() > maxHeap.size())
        {
            temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }

        double median;

        // compute median based on heaps size
        if (minHeap.size() != maxHeap.size())
            median = maxHeap.top();
        else
            median = (double)(minHeap.top() + maxHeap.top()) / 2;

        res.push_back(median);
    }

    return res;
}

int main()
{
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);

    for (double median : res)
        cout << median << " ";
    return 0;
}