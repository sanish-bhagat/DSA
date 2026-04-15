#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

string URLify(string &s)
{
    string res;

    for (char c : s)
    {
        // replace white space
        if (c == ' ')
            res += "%20";

        // add the non space char
        else
            res += c;
    }

    return res;
}

int main()
{
    string s = "i love programming";
    cout << URLify(s);
}