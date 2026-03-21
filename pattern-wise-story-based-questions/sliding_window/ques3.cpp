// A chat application logs characters typed by a user.

// Find the length of the longest substring without repeating characters.

#include<bits/stdc++.h>
using namespace std;

int longestSub(string &s) {
    vector<int> freq(26, 0);

    int left = 0, maxLen = 0;

    for(int right=0; right<s.size(); right++) {

        freq[s[right] - 'a']++;

        while(freq[s[right] - 'a'] > 1) {
            freq[s[left] - 'a']--;

            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << longestSub(s);
}