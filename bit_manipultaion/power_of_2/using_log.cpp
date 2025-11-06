#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

bool isPowerofTwo(int n)
{
    int logVal = log2(n);

    return pow(2, logVal) == n;
}

int main()
{
    int n = 16;
    if (isPowerofTwo(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}