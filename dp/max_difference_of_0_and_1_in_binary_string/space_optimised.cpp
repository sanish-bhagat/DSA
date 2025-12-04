#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxDifference(string &s)
{
    int n = s.size();

    // first character value, '0' -> +1, '1' -> -1
    int prev = (s[0] == '0') ? 1 : -1;

    int curr = 0;
    int best = prev;

    // iterate and traverse all the substrings
    for (int i = 1; i < n; i++)
    {
        // curr character value
        int val = (s[i] == '0') ? 1 : -1;

        // either extend the curr value to the substring(include)
        // or start a new substring from the curr value(exclude)
        curr = max(val, val + prev);

        // pick the best one
        best = max(best, curr);

        // update the previous value by the curr one
        prev = curr;
    }

    // return the max difference
    return best;
}

int main()
{
    string S = "11000010001";
    cout << maxDifference(S) << endl;
    return 0;
}