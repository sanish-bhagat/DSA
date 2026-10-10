#include <iostream>
using namespace std;

//! TC is O(log b), base a
//! SC is O(1)

bool balancePan(int a, int b)
{
    while (b > 0)
    {
        int rem = b % a;

        // Remainder 0 or 1 means no carry is needed.
        if (rem == 0 || rem == 1)
        {
            b /= a;
        }

        // Remainder a - 1 means use one weight on opposite side and carry 1.
        else if (rem == a - 1)
        {
            b = b / a + 1;
        }

        // Any other remainder cannot be balanced.
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int a = 4, b = 11;
    cout << boolalpha << balancePan(a, b) << endl;

    a = 3;
    b = 5;
    cout << boolalpha << balancePan(a, b) << endl;
}