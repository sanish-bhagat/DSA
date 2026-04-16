#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int myAtoi(string &s)
{
    int i = 0, n = s.size();

    // skip leading whitespaces
    while (i < n && s[i] == ' ')
        i++;

    // check for the sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;

        i++;
    }

    // build the res int
    long res = 0;
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        // overflow case
        // res * 10 + digit <= INT_MAX -> valid no.
        if (res > (INT_MAX - digit) / 10)
            return (sign == 1) ? INT_MAX : INT_MIN;

        // add the curr digit in the res
        res = res * 10 + digit;
        i++;
    }

    return sign * res;
}

int main()
{
    string s = " -0012gfg4";
    cout << myAtoi(s);
}