#include <bits/stdc++.h>
using namespace std;

string findMax(string &s, int k)
{
    // base case: no swaps left
    if (k == 0)
        return s;

    int n = s.size();
    string ans = s;

    // traverse each pairs of char
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // if its larger
            if (s[i] < s[j])
            {
                // swap them
                swap(s[i], s[j]);

                // recursively call with one less swap, and update the ans accordingly
                ans = max(ans, findMax(s, k - 1));

                // backtrack: to explore all combinations
                swap(s[i], s[j]);
            }
        }
    }

    return ans;
}

//! TC is O((n ^ 2) ^ k)
//! SC is O(k)

string findMaximumNum(string s, int k)
{
    // recursive function to find the largest no.
    return findMax(s, k);
}

int main()
{

    string s = "7599";
    int k = 2;

    cout << findMaximumNum(s, k) << endl;

    return 0;
}