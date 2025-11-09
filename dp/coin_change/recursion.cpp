#include <bits/stdc++.h>
using namespace std;

int countRec(vector<int> &coins, int n, int sum)
{
    // founded a soltuion
    if (sum == 0)
        return 1;

    // cannot find a solution
    if (sum < 0 || n == 0)
        return 0;

    // two cases -
    // either include the curr coin or exclude the curr coin
    return countRec(coins, n, sum - coins[n - 1]) + countRec(coins, n - 1, sum);
}

//! TC is O(2 ^ sum)
//! SC is O(sum)

int count(vector<int> &coins, int sum)
{
    return countRec(coins, coins.size(), sum);
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << count(coins, sum);
    return 0;
}