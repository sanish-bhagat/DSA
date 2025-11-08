#include <bits/stdc++.h>
using namespace std;

//! TC is O(loga)
//! SC is O(1)

long long divide(long long a, long long b)
{
    // base case -> overflow
    if (a == INT_MIN && b == -1)
        return INT_MAX;

    // quotient will be -ve if the sign of divisor and dividend are different
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

    // find the absolute value of divisor and dividend
    a = abs(a);
    b = abs(b);

    long long quotient = 0;

    // iterate through msb to lsb
    for (int i = 31; i >= 0; i--)
    {
        // find a greatest multiple of divisor that is less than or equal to the dividend
        if ((b << i) <= a)
        {
            a -= (b << i);
            quotient |= (1LL << i);
        }
    }

    // return the quotient with the sign
    return sign * quotient;
}

int main()
{
    long long a = 43, b = -8;
    cout << divide(a, b);

    return 0;
}