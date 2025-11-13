#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int countFriendsPairings(int n)
{
    int a = 1, b = 2, c = 0;

    // base case => f(0) = 0 -> empty set, no combination options possible
    // f(1) = 1 -> only single option
    // f(2) = 2 -> either both single or one pair option
    if (n <= 2)
        return n;

    // use fibonacci number idea to find the possible count of pairs
    for (int i = 3; i <= n; i++)
    {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }

    return c;
}

int main()
{
    int n = 4;
    cout << countFriendsPairings(n) << endl;
    return 0;
}