#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int minimumStep(int n)
{
    int res = 0;

    while (n > 1)
    {
        // if n is divisible by 3, reduce n and increment edge cnt
        if (n % 3 == 0)
        {
            res++;
            n /= 3;
        }

        // else reduce n by 1 and increment edge cnt
        else
        {
            res++;
            n--;
        }
    }

    return res;
}

int main()
{
    int n = 4;
    cout << minimumStep(n) << endl;

    return 0;
}