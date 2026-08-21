#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int transform(string &s1, string &s2)
{
    // strings differ by size
    if (s1.size() != s2.size())
        return -1;

    // hashmap to count frequency
    unordered_map<char, int> mp;

    // freq count for s1
    for (char c : s1)
        mp[c]++;

    // cancel out freq
    for (char c : s2)
    {
        if (mp.count(c))
            mp[c]--;
    }

    // if any char is present which is not present in any of the strings
    // return -1, cannot be transformed
    for (auto it : mp)
        if (it.second != 0)
            return -1;

    int n = s1.size();

    // traverse from right to left
    int i = n - 1, j = n - 1, res = 0;

    while (i >= 0 && j >= 0)
    {
        // character mismatch, count operation required and move only i ptr
        while (i >= 0 && s1[i] != s2[j])
        {
            res++;
            i--;
        }

        // move both ptrs
        i--, j--;
    }

    return res;
}

int main()
{
    string s1 = "GeeksForGeeks";
    string s2 = "ForGeeksGeeks";

    cout << transform(s1, s2) << endl;

    return 0;
}