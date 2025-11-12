#include <bits/stdc++.h>
using namespace std;

// gives the binomial coefficient of n -> nCr
long long binomialCoeff(int n, int r)
{
    if (r > (n - r))
        r = n - r;

    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

//! TC is O(n)
//! SC is O(1)

int findCatalan(int n)
{
    // find C(2n, n) -> binomial coefficient
    long long c = binomialCoeff(2 * n, n);

    // nth catalan no. = C(2n, n) / (n + 1)
    return (int)c / (n + 1);
}

int main()
{
    int n = 6;
    int res = findCatalan(n);
    cout << res;
    return 0;
}