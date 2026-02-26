#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool areIsomorphic(string &s1, string &s2)
{
    // hash vectors for both the strings respectively
    vector<int> m1(256, 0), m2(256, 0);

    for (int i = 0; i < s1.size(); i++)
    {
        // characters have different mappings -> return false
        if (m1[s1[i]] != m2[s2[i]])
            return false;

        // make the mapping
        m1[s1[i]] = i + 1;
        m2[s2[i]] = i + 1;
    }

    return true;
}

int main()
{
    string s1 = "aab", s2 = "xxy";
    cout << areIsomorphic(s1, s2);
}