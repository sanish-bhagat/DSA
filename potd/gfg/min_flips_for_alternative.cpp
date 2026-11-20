#include <bits/stdc++.h>
using namespace std;

// count flips for a given starting char
int solve(string &s, char expected)
{
    int cnt = 0;

    for (char c : s)
    {
        // need to flip the char
        if (c != expected)
            cnt++;

        // next iteration expected char
        expected = (expected == '0') ? '1' : '0';
    }

    return cnt;
}

//! TC is O(n)
//! SC is O(1)

int minFlips(string &s)
{
    // return the minimum flips for both possible starting characters
    return min(solve(s, '0'), solve(s, '1'));
}

int main()
{
    string s = "0001010111";
    cout << minFlips(s);
}