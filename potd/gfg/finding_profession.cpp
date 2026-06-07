#include <bits/stdc++.h>
using namespace std;

// count no. of set bits
int countSetBits(int n)
{
    int cnt = 0;
    while (n)
    {
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

//! TC is O(log pos)
//! SC is O(1)

string profession(int level, int pos)
{
    // count the no. of set bits
    int cnt = countSetBits(pos - 1);

    // set bit count is even -> return "doctor", else return "engineer"
    return (cnt % 2) ? "Doctor" : "Engineer";
}

int main()
{
    int level = 3;
    int pos = 2;

    cout << profession(level, pos);
}