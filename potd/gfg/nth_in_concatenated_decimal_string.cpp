#include <iostream>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

char nthCharacter(int n)
{
    // number of digits in current group
    int len = 1;

    // count of numbers with 'len' digits
    long long count = 9;

    // first number with 'len' digits
    long long start = 1;

    // finding which digit-length group n falls into
    while (n > len * count)
    {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    // finding the exact number within that group
    long long number = start + (n - 1) / len;

    // finding the exact digit within that number, using
    // arithmetic instead of string conversion
    int digitIndex = (n - 1) % len;
    long long divisor = 1;
    for (int i = 0; i < len - digitIndex - 1; i++)
    {
        divisor *= 10;
    }

    int digit = (number / divisor) % 10;

    return '0' + digit;
}

int main()
{
    int n = 10;
    cout << "'" << nthCharacter(n) << "'";

    return 0;
}