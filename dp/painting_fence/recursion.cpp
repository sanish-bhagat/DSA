#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int countWays(int n, int k)
{
    // base case -> last two posts are painted as different
    if (n == 1)
        return k;

    // base case -> last two posts painted with same color
    if (n == 2)
        return k * k;

    // ways in which last fence is of different color
    int cnt1 = countWays(n - 1, k) * (k - 1);

    // ways in which last two fences are of different color
    int cnt2 = countWays(n - 2, k) * (k - 1);

    // return the total no. of ways
    return cnt1 + cnt2;
}

int main()
{

    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}