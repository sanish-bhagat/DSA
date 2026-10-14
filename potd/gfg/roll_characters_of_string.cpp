#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string findRollOut(string &s, vector<int> &roll)
{
    int n = s.size(), m = roll.size();

    // diff[]
    vector<int> diff(n + 1, 0);

    // apply range updates
    for (int i = 0; i < m; i++)
    {
        diff[0] += 1;

        if (roll[i] < n)
            diff[roll[i]] -= 1;
    }

    // prefix sum to get total shifts
    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];

    // apply shifts
    for (int i = 0; i < n; i++)
    {
        int shift = diff[i] % 26;

        s[i] = char('a' + (s[i] - 'a' + shift) % 26);
    }

    return s;
}

int main()
{
    string s = "zcza";

    vector<int> roll = {1, 1, 3, 4};

    cout << findRollOut(s, roll) << endl;

    return 0;
}