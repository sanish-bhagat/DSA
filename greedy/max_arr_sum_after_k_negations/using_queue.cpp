#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

long long int maximizeSum(vector<int> &arr, int k)
{
    int n = arr.size();

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // build min heap with arr[] elements
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    // perform k modifications, every time pop the min element and apply negations operation
    for (int i = 0; i < k; i++)
    {
        int top = pq.top();
        pq.pop();
        pq.push(-1 * top);
    }

    // calculate the sum after the modifications
    long long int sum = 0;
    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();

        sum += top;
    }

    return sum;
}

int main()
{
    vector<int> arr = {-2, 0, 5, -1, 2};
    int k = 4;
    cout << maximizeSum(arr, k);
    return 0;
}