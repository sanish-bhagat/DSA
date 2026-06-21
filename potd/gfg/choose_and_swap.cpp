#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

string chooseSwap(string &s)
{
    int n = s.size();

    // stores the first occuring index of every char
    vector<int> first(26, -1);
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (first[c] == -1)
            first[c] = i;
    }

    // keep track of positions and chars to be swapped
    char from = 0, to = 0;
    int pos = -1;

    for (int i = 0; i < n; i++)
    {
        // traverse till curr index
        int curr = s[i] - 'a';

        for (int c = 0; c < curr; c++)
        {
            // If a smaller character exists after position i,
            // swapping these two characters can improve the string.
            if (first[c] > i)
            {
                from = s[i];
                to = char(c + 'a');
                pos = i;
                break;
            }
        }

        if (pos != -1)
            break;
    }

    // no swap needed, s is already lexicographically smaller
    if (pos == -1)
        return s;

    // swap all the occurences
    for (char &c : s)
    {
        if (c == to)
            c = from;

        else if (c == from)
            c = to;
    }

    return s;
}

int main()
{
    string s = "ccad";
    cout << chooseSwap(s);
}