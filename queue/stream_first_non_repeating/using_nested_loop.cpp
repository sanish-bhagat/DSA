#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

string firstNonRepeating(string &s)
{
    vector<int> freq(26, 0);
    int n = s.length();
    string ans;

    for (int i = 0; i < n; i++)
    {
        // set the freq of the char
        freq[s[i] - 'a']++;

        bool found = false;
        for (int j = 0; j <= i; j++)
        {
            // if char have freq == 1 then append it to the ans
            if (freq[s[j] - 'a'] == 1)
            {
                ans.push_back(s[j]);
                found = true;
                break;
            }
        }

        // if not found then append '#' in the ans
        if (!found)
        {
            ans.push_back('#');
        }
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