#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int smallestSubstring(string &s)
{
    // keep cnt track
    int zeroCnt = 0, oneCnt = 0, twoCnt = 0;

    // use sliding window technique on the gievn string
    int left = 0, minLen = INT_MAX;

    for (int right = 0; right < s.size(); right++)
    {
        // include the char in the curr substring
        if (s[right] == '0')
            zeroCnt++;

        else if (s[right] == '1')
            oneCnt++;

        else
            twoCnt++;

        // shrink the window till valid
        while (zeroCnt > 0 && oneCnt > 0 && twoCnt > 0)
        {
            // keep track of smallest valid substring
            minLen = min(minLen, right - left + 1);

            // exclude the char from curr window
            if (s[left] == '0')
                zeroCnt--;

            else if (s[left] == '1')
                oneCnt--;

            else
                twoCnt--;

            left++;
        }
    }

    return (minLen == INT_MAX) ? -1 : minLen;
}

int main()
{
    string s = "022001";
    cout << smallestSubstring(s);
}