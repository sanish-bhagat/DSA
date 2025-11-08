#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int square(int n)
{
    if (n < 0)
        n = -n;

    int res = n;

    // keep adding 'n' in the res n times -> gives n * n
    for (int i = 1; i < n; i++)
        res += n;

    return res;
}

int main()
{
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}