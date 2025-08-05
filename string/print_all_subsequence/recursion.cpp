#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * 2 ^ n)
//! SC is O(n)

void printSubsRec(string s, string curr)
{

    // base case
    if (s.empty())
    {
        cout << curr << endl;
        return;
    }

    // recursive call by including the first char of the string
    printSubsRec(s.substr(1), curr + s[0]);

    // recursive call by without including the first char of the string
    printSubsRec(s.substr(1), curr);
}

void printSubsRec(string s, int index, string curr)
{
    if (index == s.length())
    {
        cout << curr << endl;
        return;
    }

    //include the char
    printSubsRec(s, index + 1, curr + s[index]);

    //exculde the char
    printSubsRec(s, index + 1, curr);
}

void printSubs(string &s)
{

    string curr = "";
    printSubsRec(s, 0, curr);
}

int main()
{
    string s = "ab";
    printSubs(s);
    return 0;
}
