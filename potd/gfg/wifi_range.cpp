#include <bits/stdc++.h>
using namespace std;

bool wifiRange(string &s, int x)
{
    int n = s.size();

    // keep track of the rightmost covered room
    int maxReach = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            // if gap exists between previous coverage and current wifi
            if (maxReach < i - x - 1)
                return false;

            // update maxReach
            maxReach = max(maxReach, i + x);
        }
    }

    // all positions have been covered -> return true
    return maxReach >= n - 1;
}

int main()
{
    int x = 1;
    string s = "10010";
    cout << wifiRange(s, x);
}