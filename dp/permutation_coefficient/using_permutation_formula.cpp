#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int permutationCoeff(int n, int k)
{
    int P = 1;

    // P(n, k) = n * (n - 1) * (n - 2) ... (n - k + 1)
    for (int i = 0; i < k; i++)
        P *= (n - i);

    return P;
}

int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << " " << k << ") is " << permutationCoeff(n, k);

    return 0;
}