#include <iostream>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int findPosition(int n)
{
    // no set bit or more than one set bit present -> return -1
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    // start from value 1 -> 01(binary)
    int pos = 1, val = 1;

    while ((val & n) == 0)
    {
        // left shift
        val = val << 1;
        pos++;
    }

    // return the pos
    return pos;
}

int main()
{
    int n = 4;
    cout << findPosition(n);
}