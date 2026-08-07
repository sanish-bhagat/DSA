#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countFriendsPairings(int n)
{
    // base case
    if (n <= 2)
        return n;

    // use fibonacci idea
    int a = 1, b = 2, c = 0;

    for (int i = 3; i <= n; i++)
    {
        // for ith friend it can pair, f(i) = f(i - 1) + (i - 1) * f(a)
        c = b + (i - 1) * a;

        // update the states
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n = 3;
    cout << countFriendsPairings(n);
}