#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int longestRepeatingSubsequence(string &s)
{

    int n = s.length();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            //char match at different index
            if (s[i - 1] == s[j - 1] && i != j)
                curr[j] = 1 + prev[j - 1];

            else
                curr[j] = max(prev[j], curr[j - 1]); //exclude one char
        }

        //copy curr row value to prev row
        prev = curr;
    }

    return prev[n];
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}