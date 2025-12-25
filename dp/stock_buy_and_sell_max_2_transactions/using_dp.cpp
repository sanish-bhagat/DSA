#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxProfit(vector<int> &price)
{
    int n = price.size();

    // 2d[] to keep track of values from ahead -> day(i + 1) and curr -> day(i)
    vector<vector<int>> ahead(3, vector<int>(2, 0)), curr(3, vector<int>(2, 0));

    // traverse the prices from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 1; k <= 2; k++)
        {
            // if we can buy, either buy or skip the day
            curr[k][1] = max(ahead[k][0] - price[i], ahead[k][1]);

            // if we can sell, either sell or skip the day
            curr[k][0] = max(ahead[k - 1][1] + price[i], ahead[k][0]);
        }

        // update the ahead day values by the curr day ones
        ahead = curr;
    }

    // return the max profit from atmost k transactions
    return ahead[2][1];
}

int main()
{
    vector<int> price = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(price);
    return 0;
}