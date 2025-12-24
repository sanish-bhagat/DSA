#include <bits/stdc++.h>
using namespace std;

int maxProfitRec(int i, int k, int buy, vector<int> &prices, vector<vector<vector<int>>> &memo)
{
    // base case: all transactions completed
    if (k <= 0 || i >= prices.size())
        return 0;

    // already computed subproblem
    if (memo[i][k][buy] != -1)
        return memo[i][k][buy];

    int res = 0;

    // we can buy, either buy(at price[i]) or skip it
    if (buy)
        res = max(maxProfitRec(i + 1, k, 0, prices, memo) - prices[i], maxProfitRec(i + 1, k, 1, prices, memo));

    // we can sell, either sell(earn profit of price[i]) or skip it
    else
        res = max(prices[i] + maxProfitRec(i + 1, k - 1, 1, prices, memo), maxProfitRec(i + 1, k, 0, prices, memo));

    return memo[i][k][buy] = res;
}

//! TC is O(n * k)
//! SC is O(n * k)

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    // 3d memo matrix -> memo[i][k][buy]
    // i -> curr day, k -> transactions left, buy = 1 if we can buy or else 0
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

    return maxProfitRec(0, k, 1, prices, memo);
}

int main()
{
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};

    cout << maxProfit(prices, k);
    return 0;
}