#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

string minWindow(string &s, string &p)
{
    // freq hahmap
    vector<int> window(26, 0), need(26, 0);

    int left = 0, start = 0, minLen = INT_MAX;

    int required = 0, formed = 0;

    // store the freq of every letter in p
    for (char c : p)
        need[c - 'a']++;

    // find the no. of required letters(present in p, including duplicates)
    for (int i = 0; i < 26; i++)
    {
        if (need[i] > 0)
            required++;
    }

    // use sliding window to find the smallest substring
    for (int right = 0; right < s.size() - 1; right++)
    {
        // expand the window -> include the curr element in the curr window
        char c = s[right];
        window[c - 'a']++;

        // curr letter in the window matches the freq in the p string
        if (need[c - 'a'] > 0 && window[c - 'a'] == need[c - 'a'])
            formed++;

        // shrink the window
        while (formed == required)
        {
            // store the minLen, and start of the substring
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }

            // remove the element from the curr window
            char ch = s[left];
            window[ch - 'a']--;

            // if freq mismatches than the required in p string -> decrement the formed count
            if (need[ch - 'a'] > 0 && window[ch - 'a'] < need[ch - 'a'])
                formed--;

            // move left ptr forward
            left++;
        }
    }

    // return the smallest substring
    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main()
{
    string s = "timetopractice";
    string p = "toc";

    string res = minWindow(s, p);

    for (char c : res)
        cout << c;
}