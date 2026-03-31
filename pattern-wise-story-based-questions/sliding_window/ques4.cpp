// A document search engine needs to find the smallest substring
// in a document that contains all characters of a given keyword.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

string minWindowSubstr(string &s, string &t)
{
    // keep track of freq of chars in string t
    vector<int> need(256, 0);

    // freq of letters in curr window
    vector<int> window(256, 0);

    int required = 0;

    // build the need freq hashmap
    for (char c : t)
    {
        // increment the required unique letter count
        if (need[c] == 0)
            required++;

        need[c]++;
    }

    int formed = 0;

    int left = 0, minLen = INT_MAX, start = 0;

    // slide window through the string s
    for (int right = 0; right < s.size(); right++)
    {
        // include the curr letter in the curr window
        char c = s[right];
        window[c]++;

        // letter in curr window's freq matches as per required
        if (need[c] > 0 && window[c] == need[c])
            formed++;

        // shrink the window till valid
        while (left <= right && formed == required)
        {
            // store the minLen substr
            if (right - left + 1 < minLen)
            {
                start = left;
                minLen = right - left + 1;
            }

            // remove the letter from the window
            char ch = s[left];
            window[ch]--;

            left++;

            // after shrinking freq mismatches -> decrement the formed count
            if (need[ch] > 0 && window[ch] < need[ch])
                formed--;
        }
    }

    // return the minLen substr
    return s.substr(start, minLen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindowSubstr(s, t);
}