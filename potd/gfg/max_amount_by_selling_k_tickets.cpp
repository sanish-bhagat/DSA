#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + k*logn)
//! SC is O(n)

int maxAmount(vector<int> &arr, int k)
{
    int mod = 1e9 + 7;
    int sum = 0;

    // max heap
    priority_queue<int> pq(arr.begin(), arr.end());

    // sell k tickets and maximise the sell
    while (k-- && !pq.empty())
    {
        // curr max ticket price
        int top = pq.top();
        pq.pop();

        // sell it and decrement the next ticket price
        sum = (sum + top) % mod;
        top = top - 1;

        // the curr ticket is having the max price,
        // keep on selling it until a better is not found
        while (k > 0 && !pq.empty() && top >= pq.top())
        {
            sum = (sum + top) % mod;
            top = top - 1;
            k--;
        }

        // push the curr ticket leftout price
        if (top > 0)
            pq.push(top);
    }

    return sum;
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 4};
    int k = 3;

    cout << maxAmount(arr, k);

    return 0;
}