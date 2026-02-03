#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxProfit(vector<int> &prices)
{
    int profit = 0, mini = prices[0];

    // traverse through the stock prices
    for (int i = 0; i < prices.size(); i++)
    {
        // pick the min stock price seen so far
        mini = min(mini, prices[i]);

        // curr profit
        int curr = prices[i] - mini;

        // update the overall maxProfit
        profit = max(profit, curr);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}