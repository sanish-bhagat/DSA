#include <bits/stdc++.h>
using namespace std;

int getCountRec(int i, int j, int n, vector<vector<vector<int>>> &memo)
{
    // base case: cell out of range
    if (i < 0 || i >= 4 || j < 0 || j >= 3 || (i == 3 && (j == 0 || j == 2)))
        return 0;

    // reminaing length is 1
    if (n == 1)
        return 1;

    // already computed subproblem
    if (memo[n][i][j] != -1)
        return memo[n][i][j];

    // directions for traversal at every curr cell
    vector<vector<int>> dir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int ans = 0;

    // recursively traverse in every direction
    for (auto d : dir)
    {
        int x = i + d[0], y = j + d[1];
        ans += getCountRec(x, y, n, memo);
    }

    return memo[n][i][j] = ans;
}

//! TC is O(n)
//! SC is O(n)

int getCount(int n)
{
    // 3d memo[]
    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));

    int ans = 0;

    // traverse every cell position and recursively call for every directions
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans += getCountRec(i, j, n, memo);
        }
    }

    return ans;
}

int main()
{

    int n = 1;
    cout << getCount(n);
    return 0;
}