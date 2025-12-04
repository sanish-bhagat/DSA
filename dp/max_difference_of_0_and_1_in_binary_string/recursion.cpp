#include <bits/stdc++.h>
using namespace std;

int helper(int i, int n, string &s, int currSum, int &best)
{
    // base case: reached end of the substring
    if (i == n)
        return 0;

    // '0' -> +1, '1' -> -1
    int val = (s[i] == '0') ? 1 : -1;

    // either we extend the curr value to the previous sum(include) or we start a new substring(exclude)
    currSum = max(val, val + currSum);

    // pick the best one
    best = max(best, currSum);

    // recursively move to the next index
    helper(i + 1, n, s, currSum, best);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int maxDifference(string &s)
{
    int n = s.size();

    // all are 1's -> return -1
    if (count(s.begin(), s.end(), '1') == n)
        return -1;

    int best = INT_MIN;

    // recursively traverse all the substrings
    helper(0, n, s, 0, best);

    return best;
}

int main()
{
    string S = "11000010001";
    cout << maxDifference(S) << endl;
    return 0;
}