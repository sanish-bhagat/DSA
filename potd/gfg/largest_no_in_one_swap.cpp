#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

string largestSwap(string &s)
{
    // keep track of the max digit seen so far in the right
    char maxDigit = '0';
    int maxIdx = -1;

    // l -> index of smaller digit to swap with
    // r -> index of larger digit to swap with
    int l = -1, r = -1;

    // traverse from right to left
    for (int i = s.size() - 1; i >= 0; i--)
    {
        // curr digit is larger -> update maxDigit
        if (s[i] > maxDigit)
        {
            maxDigit = s[i];
            maxIdx = i;
        }

        // founded a smaller digit before larger(maxDigit) one
        else if (s[i] < maxDigit)
        {
            l = i;
            r = maxIdx;
        }
    }

    // no swap needed
    if (l == -1)
        return s;

    // swap and return the largest no. possible
    swap(s[l], s[r]);

    return s;
}

int main()
{
    string s = "768";
    cout << largestSwap(s);
}