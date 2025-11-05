#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int countSetBits(int n)
{
    int count = 0;

    while (n > 0)
    {
        // keep removing the least significant set bit from n
        n &= (n - 1);

        // counts how many times the loop runs -> gives the no. of set bits in 'n'
        count++;
    }

    return count;
}

int main()
{
    int N = 9;

    // Function call
    cout << countSetBits(N) << endl;
    return 0;
}