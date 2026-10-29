#include <bits/stdc++.h>
using namespace std;

//! TC is O(n logn)
//! SC is O(n)

int minComputation(vector<int> &files)
{
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());

    int res = 0;

    while (pq.size() > 1)
    {
        // get the top 2 min elements
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        // merge the files and include the cost
        res += (a + b);
        pq.push(a + b);
    }

    return res;
}

int main()
{
    vector<int> files = {2, 3, 6, 5, 7, 4};
    cout << minComputation(files);
}