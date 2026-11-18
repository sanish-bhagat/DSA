#include <iostream>

using namespace std;

// function to compute cumulative XOR sum from 1 to n in O(1)
int computeXOR(int n)
{
    // remainder determines the cycle position
    int rem = n % 4;

    // if n is a multiple of 4, the XOR sum equals n
    if (rem == 0)
        return n;

    // if n leaves remainder 1, all preceding pairs cancel out, leaving 1
    if (rem == 1)
        return 1;

    // if n leaves remainder 2, the XOR sum evaluates to n + 1
    if (rem == 2)
        return n + 1;

    // if n leaves remainder 3, all numbers fully cancel out to 0
    return 0;
}

//! TC is O(1)
//! SC is O(1)

int findXOR(int l, int r)
{
    // compute cumulative XOR from 1 up to r
    int xorR = computeXOR(r);

    // compute cumulative XOR from 1 up to l - 1
    int xorLMinus1 = computeXOR(l - 1);

    // cancel out elements from 1 to l - 1 using x ^ x = 0 to get range [l, r]
    return xorR ^ xorLMinus1;
}

int main()
{
    int l = 4, r = 8;

    cout << findXOR(l, r) << "\n";

    return 0;
}