#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int getMaxWeight(string &s)
{
    int n = s.size();

    // next1 stores the ans for i + 1, and next2 for i + 2
    int next1 = 0, next2 = 0;

    // traverse the string from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // case1 : consider curr character as a single character
        int curr = 1 + next1;

        // case2 : pair curr character with next one
        if (i + 1 < n)
        {
            // diff pairs adds up 4, same adds up 3
            int pairWeight = s[i] != s[i + 1] ? 4 : 3;

            // take the max of both choices
            curr = max(curr, pairWeight + next2);
        }

        // update values for further iteration
        next2 = next1;
        next1 = curr;
    }

    return next1;
}

int main()
{

    string s = "ABB";

    cout << getMaxWeight(s) << endl;

    return 0;
}