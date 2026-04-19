#include <bits/stdc++.h>
using namespace std;

bool isPower(int x, int y)
{
    // base cases, x ^ 0 = 1
    if (y == 1)
        return true;

    if (x == 0 || x == 1)
        return (x == y);

    long long power = 1;

    // keep on multiplying, until we reach y
    while (power < y)
        power *= x;

    // y is a power of x -> return true, else false
    return power == y;
}

int main()
{
    int x = 3, y = 21;
    cout << isPower(x, y);
}