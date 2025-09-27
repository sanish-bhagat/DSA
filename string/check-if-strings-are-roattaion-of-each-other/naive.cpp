#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

bool areRotations(string &s1, string &s2)
{

    int n = s1.size();

    for (int i = 0; i < n; i++)
    {

        if (s1 == s2)
            return true;

        // right rotate
        char last = s1.back();
        s1.pop_back();
        s1 = last + s1;
    }

    return false;
}

int main()
{
    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1, s2) ? "true" : "false");
    return 0;
}