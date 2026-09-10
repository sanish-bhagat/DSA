#include <bits/stdc++.h>
using namespace std;

//! TC is O(√(y/x) log(y/x))
//! SC is O(1)

int pairCount(int x, int y)
{
    int n = 0, res = 0;

    // lcm must be divisible by gcd, else no pair exists
    if (y % x == 0)
        n = y / x;

    // if n is 1, the only pair is (x, x)
    if (n == 1)
        res = 1;

    // find coprime factor pairs (i, n/i) of n
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int j = n / i;

            // both (x*i, x*j) and (x*j, x*i) are valid
            // only if i and j are coprime (gcd = 1)
            if (i != j && __gcd(x * i, x * j) == x)
                res += 2;
        }
    }

    return res;
}

int main()
{
    int x = 2, y = 12;

    cout << pairCount(x, y) << endl;

    return 0;
}