#include <bits/stdc++.h>
using namespace std;

// Helper to calculate (base^exp) % mod
long long power(long long base, long long exp)
{
    long long res = 1;
    long long mod = 1000000007;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Helper to find modular inverse using Fermat's Little Theorem
long long modInverse(long long n)
{
    return power(n, 1000000007 - 2);
}

//! TC is O(min(x, y) * log(mod))
//! SC is O(1)

int ways(int x, int y)
{
    long long mod = 1000000007;
    int n = x + y;
    int r = min(x, y);
    long long ans = 1;

    // Calculate nCr % mod
    for (int i = 1; i <= r; i++)
    {

        // Multiply by (n - i + 1)
        ans = (ans * (n - i + 1)) % mod;

        // Divide by i using modular inverse
        ans = (ans * modInverse(i)) % mod;
    }

    return (int)ans;
}

int main()
{
    int x = 3, y = 6;
    cout << ways(x, y) << endl;
    return 0;
}