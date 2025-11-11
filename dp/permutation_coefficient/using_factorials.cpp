#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int permutationCoeff(int n, int k)
{
    // store the factorial of every no.
    int fact[n + 1];

    // base case f(0) = 1
    fact[0] = 1;

    // calculate the factorial of every no. iteratively
    for (int i = 1; i <= n; i++)
        fact[i] = i * fact[i - 1];

    // P(n, k) = n!/(n - k)!
    return fact[n] / fact[n - k];
}

int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << " " << k << ") is " << permutationCoeff(n, k);

    return 0;
}