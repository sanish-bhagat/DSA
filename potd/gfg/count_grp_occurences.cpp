#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int getCount(string &s, int k)
{
    int n = s.size();

    // freq hashmap -> stores the no. of grps in which letter is occuring
    vector<int> freq(26, 0);

    int i = 0;

    while (i < n)
    {
        int j = i;

        // skip duplicate characters
        while (j < n && s[j] == s[i])
            j++;

        // include the curr letter in the hashmap
        freq[s[i] - 'a']++;

        // move ptr forward to the next grp
        i = j;
    }

    // count characters having k groups
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == k)
            res++;
    }

    return res;
}

int main()
{
    string s = "geeksforgeeks";
    int k = 2;

    cout << getCount(s, k);
}