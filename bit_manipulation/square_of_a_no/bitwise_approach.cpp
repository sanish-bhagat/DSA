#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int square(int n)
{
    if (n < 0)
        n = -n;

    int power = 0, temp = n, res = 0;

    while (temp > 0)
    {
        // check the lsb
        if (temp & 1)
        {

            // update the res, res = res + n^power
            res += (n << power);
        }

        power++;

        // temp = temp / 2
        temp = temp >> 1;
    }

    return res;
}

int main()
{
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}