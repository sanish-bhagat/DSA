#include <bits/stdc++.h>
using namespace std;

//! TC is O(n log n)
//! SC is O(n)
int minCost(int arr[], int n)
{
    // create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int cost = 0;

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main()
{
    int arr[4] = {4, 3, 2, 6};

    cout << minCost(arr, 4);
}