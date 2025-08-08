#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int profit = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int res = arr[j] - arr[i];
            profit = max(res, profit);
        }
    }

    return profit;
}

int main()
{
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
}