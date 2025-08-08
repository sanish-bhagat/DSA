#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int minCost(vector<int> &arr)
{
    int totalCost = 0;

    // create a min-heap with the elements of the arr[]
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    // process until more than 1 elements are present in the min-heap
    while (pq.size() > 1)
    {
        // get the first two small elements
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        // calculate the curr cost and totalCost
        int cost = first + second;
        totalCost += cost;

        // insert the new rope cost into the min-heap for further calculation
        pq.push(cost);
    }

    return totalCost;
}

int main()
{

    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr);
    return 0;
}