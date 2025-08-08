#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxLength(string &s)
{
    int maxLen = 0;

    //initialise the counts
    int open = 0, close = 0;

    //left -> right traversal handles too many ')' early on
    //right -> left traversal handles too many '(' early on

    //left -> right traversal
    for (char ch : s)
    {
        if (ch == '(')
            open++;

        else if (ch == ')')
            close++;

        //if both counters become equal then update maxLen
        if (open == close)
            maxLen = max(maxLen, 2 * close);

        //if more cloding brackets are present reset the counters to 0
        else if (close > open)
            close = open = 0;
    }

    //reset the counters for right -> left traversal
    open = close = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] == '(')
            open++;

        else if (s[i] == ')')
            close++;

        //if both counters are equal update maxLen,
        //keep in mind when traversing from right -> left opening {'('} bracket is treated as closing one(just for assumption) as we are traversing from back
        if (open == close)
            maxLen = max(maxLen, 2 * open);

        else if (open > close)
            open = close = 0;
    }

    return maxLen;
}

int main()
{
    string s = ")()())";
    cout << maxLength(s) << endl;

    return 0;
}