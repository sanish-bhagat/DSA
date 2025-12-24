#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // postfix profit[] -> profit[i] stores the max profit if buying at i or after it
    vector<int> profit(n, 0);

    int maxPrice = prices[n - 1];

    // traverse from right to left and fill the profit[] with maxProfit
    for (int i = n - 2; i >= 0; i--)
    {
        // maxprice from prices[i...n-1]
        maxPrice = max(maxPrice, prices[i]);

        // update with the maxProfit
        profit[i] = max(profit[i + 1], maxPrice - prices[i]);
    }

    int minPrice = prices[0], res = 0;

    // traverse from left to right and pick the best single transaction along with the profit from the second transaction
    for (int i = 1; i < n; i++)
    {
        // min price seen so far
        minPrice = min(minPrice, prices[i]);

        // update the max combined profit from both the transactions
        res = max(res, profit[i] + (prices[i] - minPrice));
    }

    // return the max profit from both the transactions
    return res;
}

int main()
{
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices);
    return 0;
}