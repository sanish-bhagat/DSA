#include <bits/stdc++.h>
using namespace std;

//! TC is O(d)
//! SC is O(1)

string smallestNumber(int s, int d)
{
    if (s < 1 || s > 9 * d)
        return "-1";

    // res num
    string res(d, '0');

    // reserve 1 place for the leftmost digit
    s--;

    // fill digits from right to left
    for (int i = d - 1; i > 0; i--)
    {
        if (s > 9)
        {
            res[i] = '9';
            s -= 9;
        }
        else
        {
            res[i] = '0' + s;
            s = 0;
        }
    }

    // place the leftmost digit
    res[0] = '1' + s;

    return res;
}

int main()
{

    int s = 9, d = 2;

    cout << smallestNumber(s, d) << endl;
    return 0;
}