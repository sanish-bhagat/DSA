#include <bits/stdc++.h>
using namespace std;

int countRecur(vector<int> &coins, int n, int sum, vector<vector<int>> &memo)
{
    // base case -> founded a solution
    if (sum == 0)
        return 1;

    // no possible way to find a solution
    if (sum < 0 || n == 0)
        return 0;

    // subproble already been computed
    if (memo[n - 1][sum] != -1)
        return memo[n - 1][sum];

    // two cases -> either include the curr coin or exclude the curr coin
    return memo[n - 1][sum] = countRecur(coins, n, sum - coins[n - 1], memo) +
                              countRecur(coins, n - 1, sum, memo);
}

//! TC is O(n * sum)
//! SC is O(n * sum)

int count(vector<int> &coins, int sum)
{
    // 2D memo table
    vector<vector<int>> memo(coins.size(), vector<int>(sum + 1, -1));
    return countRecur(coins, coins.size(), sum, memo);
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}