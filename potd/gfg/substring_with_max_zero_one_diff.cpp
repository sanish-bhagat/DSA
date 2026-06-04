#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSubstring(string &s)
{
    // first character value, '0' -> +1, '1' -> -1
    int prev = (s[0] == '0') ? 1 : -1;

    int best = prev;
    int curr;

    // iterate through the string
    for (int i = 1; i < s.size(); i++)
    {
        // curr character value
        int val = (s[i] == '0') ? 1 : -1;

        // either extend the curr value to the substring(include)
        // or start a new substring from the curr value(exclude)
        curr = max(val, val + prev);

        // pick the best one
        best = max(best, curr);

        // update the prev state
        prev = curr;
    }

    return best;
}

int main()
{
    string s = "11000010001";
    cout << maxSubstring(s);
}