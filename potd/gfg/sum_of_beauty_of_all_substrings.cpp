#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int beautySum(string &s)
{
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // curr substring char freq
        vector<int> freq(26, 0);

        for (int j = i; j < s.size(); j++)
        {
            // include the curr letter freq in substring
            freq[s[j] - 'a']++;

            int mn = INT_MAX, mx = 0;

            // find max and min freq of non-zero
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }

            // include the curr beauty diff
            ans += (mx - mn);
        }
    }

    return ans;
}

int main()
{
    string s = "aaac";
    int res = beautySum(s);

    cout << res << '\n';

    return 0;
}