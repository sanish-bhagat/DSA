#include <bits/stdc++.h>
using namespace std;

int maxProfitRec(int i, int k, int buy, vector<int> &prices)
{
    // base case: all transactions are over
    if (k <= 0 || i >= prices.size())
        return 0;

    int res = 0;

    // we can buy, either buy(at price[i]) or skip it
    if (buy)
        res = max(maxProfitRec(i + 1, k, 0, prices) - prices[i], maxProfitRec(i + 1, k, 1, prices));

    // we can sell, either sell(earn profit of price[i]) or skip it
    else
        res = max(prices[i] + maxProfitRec(i + 1, k - 1, 1, prices), maxProfitRec(i + 1, k, 0, prices));

    return res;
}

//! TC is O(2 ^ n)
//! SC is O(n)

int maxProfit(vector<int> &prices, int k)
{
    return maxProfitRec(0, k, 1, prices);
}

int main()
{
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};

    cout << maxProfit(prices, k);
    return 0;
}