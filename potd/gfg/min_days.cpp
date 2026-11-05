#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int getMinimumDays(string &s, vector<int> &p)
{
    int n = s.size();
    int t = 0;

    // calculate the initial number of consecutive same characters
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            t++;
    }

    // if there are no consecutive same characters, return 0
    if (t == 0)
        return 0;

    // iterate through one positions at a time
    for (int i = 0; i < n; i++)
    {
        int in = p[i];

        // reduce the count of consecutive equal characters
        if (in - 1 >= 0 && s[in] == s[in - 1])
            t--;

        if (in + 1 < n && s[in] == s[in + 1])
            t--;

        // mark the character as changes
        s[in] = '?';

        // if no consecutive equal characters remain, return the ans
        if (t == 0)
            return i + 1;
    }

    return n;
}

int main()
{
    string s = "aabb";
    vector<int> p = {2, 1, 3, 0};

    cout << getMinimumDays(s, p) << endl;

    return 0;
}