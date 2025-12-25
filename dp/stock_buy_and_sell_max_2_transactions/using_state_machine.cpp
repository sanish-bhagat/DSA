#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxProfit(vector<int> &price)
{
    int n = price.size();

    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    // traverse the price[] from left to right
    for (int i = 0; i < n; i++)
    {
        // keep on maximising the profit
        firstBuy = max(firstBuy, -price[i]);
        firstSell = max(firstSell, firstBuy + price[i]);
        secondBuy = max(secondBuy, firstSell - price[i]);
        secondSell = max(secondSell, secondBuy + price[i]);
    }

    // return the max profit from atmost 2-transactions
    return secondSell;
}

int main()
{
    vector<int> price = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(price);
    return 0;
}