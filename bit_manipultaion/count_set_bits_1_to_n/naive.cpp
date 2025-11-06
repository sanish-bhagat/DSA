#include <bits/stdc++.h>
using namespace std;

int setBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        count++;

        n &= (n - 1);
    }

    return count;
}

//! TC is O(n * m)
//! SC is O(1)

int countSetBits(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        count += setBits(i);
    }

    return count;
}

int main()
{
    int i = 3;
    cout << countSetBits(i);
    return 0;
}