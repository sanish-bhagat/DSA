#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int countWithout(int n, int d)
{
    if (n <= 0)
        return 0;

    string s = to_string(n);
    int length = s.length();

    // dp[tight][started] = count of valid
    // completions from the current position onward
    int dp[2][2];

    // base case: at the end, a number counts
    // only if it actually started (non-empty)
    for (int tight = 0; tight < 2; tight++)
        for (int started = 0; started < 2; started++)
            dp[tight][started] = started;

    // build the table backward from the last
    // digit position to the first
    for (int pos = length - 1; pos >= 0; pos--)
    {
        int newDp[2][2] = {0};

        for (int tight = 0; tight < 2; tight++)
        {
            for (int started = 0; started < 2; started++)
            {
                int limit = tight ? (s[pos] - '0') : 9;
                int total = 0;

                // try every valid digit, skipping d once
                // the number has started
                for (int digit = 0; digit <= limit; digit++)
                {
                    int willStart = started || (digit != 0);

                    if (willStart && digit == d)
                        continue;

                    int newTight = tight && (digit == limit);
                    total += dp[newTight][willStart];
                }

                newDp[tight][started] = total;
            }
        }

        memcpy(dp, newDp, sizeof(dp));
    }

    return dp[1][0];
}

int main()
{
    int n = 5, d = 3;

    cout << countWithout(n, d) << endl;

    return 0;
}