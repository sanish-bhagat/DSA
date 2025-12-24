#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(k)

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    // 2d[] to keep track of values from ahead -> day(i + 1) and curr -> day(i)
    vector<vector<int>> ahead(k + 1, vector<int>(2, 0)), curr(k + 1, vector<int>(2, 0));

    // traverse the prices from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= k; j++)
        {
            // if we can buy, either buy or skip the day
            curr[j][1] = max(ahead[j][0] - prices[i], ahead[j][1]);

            // if we can sell, either sell or skip the day
            curr[j][0] = max(ahead[j - 1][1] + prices[i], ahead[j][0]);
        }

        // update the ahead day values by the curr day ones
        ahead = curr;
    }

    // return the max profit from atmost k transactions
    return ahead[k][1];
}

int main()
{
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};

    cout << maxProfit(prices, k);
    return 0;
}