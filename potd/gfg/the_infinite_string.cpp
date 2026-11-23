#include <bits/stdc++.h>
using namespace std;

//! TC is O(log(p))
//! SC is O(1)

char posInfinite(string &s, int pos)
{
    int n = s.length();

    long long len = n;
    int step = 1;

    // find the construction level containing pos
    while (len < pos)
    {
        len = 2 * len + step;
        step++;
    }

    // work backwards through the levels
    while (step > 1)
    {
        long long prevLen = (len - (step - 1)) / 2;

        // position lies in the newly inserted '$' characters
        if (pos > prevLen && pos <= prevLen + step - 1)
            return '$';

        if (pos <= prevLen)
        {
            // position belongs to the previous string
            len = prevLen;
        }
        else
        {
            // position belongs to reverse(previous string)
            pos = len - pos + 1;
            len = prevLen;
        }

        step--;
    }

    // position is inside the original string
    return s[pos - 1];
}

int main()
{
    string s = "abc";
    int pos = 7;

    cout << posInfinite(s, pos) << "\n";

    return 0;
}