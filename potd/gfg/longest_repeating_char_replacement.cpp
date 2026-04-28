#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n) -> space can be optimised by using a frequency vector of size 26(only for uppercase char)

int longestSubstr(string &s, int k)
{
    // hashmap to keep track of frequency of characters
    unordered_map<char, int> freq;

    // keep track of max freq so far
    int maxFreq = 0;

    int maxLen = 0;
    int left = 0;

    // use sliding window technique
    for (int right = 0; right < s.size(); right++)
    {
        // include the curr char in the window
        freq[s[right]]++;

        // update max freq
        maxFreq = max(maxFreq, freq[s[right]]);

        // shrink window, more than k operations are required to make all char same
        if (right - left + 1 - maxFreq > k)
        {
            freq[s[left]]--;
            left++;
        }

        // update the maxLen of the valid substring
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "ADBD";
    int k = 1;
    cout << longestSubstr(s, 1);
}