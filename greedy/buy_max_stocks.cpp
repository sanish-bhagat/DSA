#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> p;

    // make pairs(stock price, day)
    for (int i = 0; i < n; i++)
        p.push_back({price[i], i + 1});

    // sort the p[] to get the stock when price is least
    sort(p.begin(), p.end());

    int ans = 0;

    // traverse the p[]
    for (int i = 0; i < n; i++)
    {
        // find the no. of stocks that can be bought on that day
        // p[i].second -> max no. of stocks that are available on that day
        // (k / p[i].first) -> how many stocks that can you can buy based on your available money
        ans += min(p[i].second, k / p[i].first);

        // update your money with the amount that is left out after spending the money on buying the current stock
        k -= p[i].first * min(p[i].second, k / p[i].first);
    }

    return ans;
}

int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}