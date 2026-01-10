#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int k)
{
    // store frequency of every char
    int freq[26] = {0};
    int left = 0, cnt = 0, distinct = 0;;

    // itereate through the char of string
    for (int right = 0; right < s.size(); right++)
    {
        // distinct char
        if(freq[s[right] - 'a'] == 0)
            distinct++;

        // increment the frequency count
        freq[s[right] - 'a']++;

        // more distinct char then required -> shrink the curr window from left
        while (distinct > k)
        {
            freq[s[left] - 'a']--;

            // decrement the ditinct count if left char frequency count is 0
            if (freq[s[left] - 'a'] == 0)
                distinct--;

            // shrink from left
            left++;
        }

        // no. of substrinigs ending at right
        cnt += (right - left + 1);
    }

    return cnt;
}

//! TC is O(n)
//! SC is O(1)

int countSubstr(string &s, int k)
{
    // exactly(k) = atmost(k) - atmost(k - 1)
    return solve(s, k) - solve(s, k - 1);
}

int main()
{
    int k = 2;
    string s = "aba";
    cout << countSubstr(s, k);
}