#include <bits/stdc++.h>
using namespace std;

//! TC is O(n ^ 2)
//! SC is O(n)

int findCatalan(int n)
{
    // 1D[] to store ith catalan no.
    int c[n + 1];

    // base case
    c[0] = c[1] = 1;

    // use recursive formula to store the value in c[]
    for (int i = 2; i <= n; i++)
    {
        c[i] = 0;
        for (int j = 0; j < i; j++)
            c[i] += c[j] * c[i - j - 1];
    }

    return c[n];
}

int main()
{
    int n = 6;
    int res = findCatalan(n);
    cout << res;
    return 0;
}