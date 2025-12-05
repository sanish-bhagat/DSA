#include <bits/stdc++.h>
using namespace std;

int cutRodRec(int i, vector<int> &price)
{
    // rod length becomes 0 -> return profit as 0
    if (i == 0)
        return 0;

    int ans = 0;

    // explore all the ways of cutting the rod in two pieces and pick the max profit value among all
    for (int j = 1; j <= i; j++)
        ans = max(ans, price[j - 1] + cutRodRec(i - j, price));

    return ans;
}

//! TC is O(n * n)
//! SC is O(n)

int cutRod(vector<int> &price)
{
    int n = price.size();

    return cutRodRec(n, price);
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}