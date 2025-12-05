#include <bits/stdc++.h>
using namespace std;

int cutRodRec(int i, vector<int> &price, vector<int> &memo)
{
    // rod length becomes 0 -> return profit as 0
    if (i == 0)
        return 0;

    // already computed subproblem
    if (memo[i] != -1)
        return memo[i];

    // recursively explore all the possible ways of cutting the rod in two pieces and
    // compute the max profit from all of them
    int ans = 0;
    for (int j = 1; j <= i; j++)
        ans = max(ans, price[j - 1] + cutRodRec(i - j, price, memo));

    return memo[i] = ans;
}

//! TC is O(n * n)
//! SC is O(n)

int cutRod(vector<int> &price)
{
    int n = price.size();

    // 1d memo[] to keep track of max profit values for every rod length
    vector<int> memo(n + 1, -1);

    return cutRodRec(n, price, memo);
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}