#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int minOperations(int n)
{
    int ops = 0;

    // work backwards
    while (n > 0)
    {
        if (n % 2 == 0)
            n /= 2;

        else
            n -= 1;

        ops++;
    }

    return ops;
}

int main()
{
    int n = 7;
    cout << minOperations(n);
}