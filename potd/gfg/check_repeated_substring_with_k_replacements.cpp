#include <bits/stdc++.h>
using namespace std;

bool kSubstr(string &s, int k)
{
    int n = s.size();

    // string cannot be divided in equal k length substrings
    if (n % k != 0)
        return false;

    // freq hashmap
    unordered_map<string, int> mp;

    // freq count for every k length substring
    for (int i = 0; i < n; i += k)
        mp[s.substr(i, k)]++;

    // only same substring is present -> return true
    if (mp.size() == 1)
        return true;

    // more than two distinct substrings are present -> return false
    if (mp.size() != 2)
        return false;

    // One of the two distinct must appear exactly once.
    // Either the first entry appears once, or it appears
    // (n/k)-1 times to make other substring appear once.
    if (mp.begin()->second == ((n / k) - 1) || mp.begin()->second == 1)
        return true;

    return false;
}

int main()
{
    int k = 3;
    string s = "abcbedabcabc";

    cout << kSubstr(s, k);
}