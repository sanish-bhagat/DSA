#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string lexiString(string &s)
{
    string doubled = s + s;
    int n = doubled.size();

    vector<int> f(n, -1);

    // Starting index of the best rotation
    int k = 0;

    for (int j = 1; j < n; j++)
    {
        char sj = doubled[j];

        // Get previous matched position
        int i = f[j - k - 1];

        while (i != -1 && sj != doubled[k + i + 1])
        {

            // Current rotation is better
            if (sj < doubled[k + i + 1])
            {
                k = j - i - 1;
            }

            // Fall back using the failure function
            i = f[i];
        }

        if (sj != doubled[k + i + 1])
        {

            // Rotation starting at j is better
            if (sj < doubled[k])
            {
                k = j;
            }

            f[j - k] = -1;
        }
        else
        {
            // Extend the matched part
            f[j - k] = i + 1;
        }
    }

    // Return the lexicographically smallest rotation
    return doubled.substr(k, s.size());
}

int main()
{
    string s = "baca";

    cout << lexiString(s) << endl;

    return 0;
}