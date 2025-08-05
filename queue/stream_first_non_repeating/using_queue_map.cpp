#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string firstNonRepeating(string &s)
{
    int n = s.length();
    string ans = "";
    unordered_map<char, int> mp;
    queue<char> q;

    for (int i = 0; i < n; i++)
    {
        // if the char is unique puhs it in the queue
        if (mp.find(s[i]) == mp.end())
            q.push(s[i]);

        // increase the count of the curr char
        mp[s[i]]++;

        // if count of the element at the forn of the queue is more means it is not unqiue then pop it until we get any unique element
        while (!q.empty() && mp[q.front()] > 1)
            q.pop();

        // if after popping q still have char then append it into the ans
        if (!q.empty())
            ans += q.front();

        // append '#' to the ans
        else
            ans += '#';
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