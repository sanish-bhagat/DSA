#include <iostream>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int maxValue(int n)
{
    int res = n;

    // Process bits from most significant to least significant.
    for (int i = 30; i >= 2; --i)
    {
        if ((res & (1 << i)) && (res & (1 << (i - 1))) && (res & (1 << (i - 2))))
        {
            // Clear the lowest bit of the three consecutive set bits.
            res &= ~(1 << (i - 2));
        }
    }

    return res;
}

int main()
{
    int n = 7;
    cout << maxValue(n) << "\n";

    return 0;
}