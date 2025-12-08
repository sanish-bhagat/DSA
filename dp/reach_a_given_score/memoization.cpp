#include <bits/stdc++.h>
using namespace std;

int countWaysRec(int i, int n, vector<int> &points, vector<vector<int>> &memo)
{
    // base case: total score is exactly == n, valid combination
    if (n == 0)
        return 1;

    // base case: invalid case
    if (n < 0 || i == 3)
        return 0;

    // already computed subproblem
    if (memo[n][i] != -1)
        return memo[n][i];

    // for every point value, we have two choices =>

    // either take the point value
    int take = countWaysRec(i, n - points[i], points, memo);

    // or don't take the point value
    int notake = countWaysRec(i + 1, n, points, memo);

    // return the total valid combinations that can be formed
    return memo[n][i] = take + notake;
}

//! TC is O(n * n)
//! SC is O(n * n)

int countWays(int n)
{
    vector<int> points = {3, 5, 10};

    // 2d memo[][]
    vector<vector<int>> memo(n + 1, vector<int>(3, -1));

    return countWaysRec(0, n, points, memo);
}

int main()
{
    int n = 20;
    cout << countWays(n);
    return 0;
}