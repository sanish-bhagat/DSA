#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string firstNonRepeating(string &s)
{
    vector<int> freq(26, 0), first(26, -1);
    int n = s.length();
    string ans;

    // find the first occuring index of each char
    for (int i = 0; i < n; i++)
    {
        if (first[s[i]] - 'a' == -1)
            first[s[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        // increase the freq of each char present in the string
        freq[s[i] - 'a']++;

        // defalut char  and min last index
        char ch = '#';
        int x = n + 1;

        // check for the unique char using freq[] and first occurence
        for (int j = 0; j < 26; j++)
        {
            if (freq[j] == 1 && x > first[j])
            {
                ch = char(j + 'a');
                x = first[j]; // update the first occurence
            }
        }

        // update the ans
        ans += ch;
    }

    return ans;
}

int main()
{
    string s = "aabc";
    string ans = firstNonRepeating(s);
    cout << ans << endl;
    return 0;
}