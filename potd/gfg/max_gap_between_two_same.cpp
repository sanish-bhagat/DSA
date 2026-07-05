#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxCharGap(string s)
{
    // store the first occuring index of letter
    vector<int> mp(26, -1);
    int maxGap = -1;

    for (int i = 0; i < s.size(); i++)
    {
        // curr char index in mp[]
        int idx = s[i] - 'a';

        // character repeats -> try to find the max gap
        if (mp[idx] != -1)
            maxGap = max(maxGap, i - mp[idx] - 1);

        // store the first occuring index
        if (mp[idx] == -1)
            mp[idx] = i;
    }

    return maxGap;
}

int main()
{
    string s = "abcabc";
    cout << maxCharGap(s);
}