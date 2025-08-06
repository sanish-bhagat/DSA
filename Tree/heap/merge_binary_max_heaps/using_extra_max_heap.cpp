#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + m) * log(n + m)

vector<int> mergeHeaps(vector<int> a, vector<int> b, int n, int m)
{
    priority_queue<int> maxHeap;
    vector<int> res;

    // push the elements of first max-heap into the new one, it will automaticaly create the max-heap
    for (int i = 0; i < n; i++)
        maxHeap.push(a[i]);

    // push the elements of second max-heap into the new one, it will automaticaly create the max-heap
    for (int j = 0; j < m; j++)
        maxHeap.push(b[j]);

    // store the elements of the merged max-heap into an array
    while (!maxHeap.empty())
    {
        res.push_back(maxHeap.top());
        maxHeap.pop();
    }

    return res;
}

int main()
{
    // Sample Input
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size(), m = b.size();

    vector<int> merged = mergeHeaps(a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";
    return 0;
}