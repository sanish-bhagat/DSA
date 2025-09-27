#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

vector<int> computeLpsArray(string &pat)
{

    int n = pat.size();
    int len = 0;
    vector<int> lps(n);

    // 1st character ka lps value 0 hoga
    lps[0] = 0;
    int i = 1;

    //lps value [1 .... n - 1] tak generate krrlo
    while (i < n)
    {

        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {

            if (len != 0)
            {
                // update len to prev value lps value to avoid faltu comparisons
                len = lps[len - 1];
            }

            // mismatch occurs
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool kmpSearch(string &txt, string &pat)
{

    int n = txt.size(), m = pat.size();

    vector<int> lps = computeLpsArray(pat);

    int i = 0, j = 0;

    while (i < n)
    {

        if (txt[i] == pat[j])
            i++, j++;

        if (j == m) // pura pattern string traverse ho chuka h
            return true;

        else if (i < n && txt[i] != pat[j])
        {

            if (j != 0)
            {
                // update j to prev lps value to avoid faltu comparisons
                j = lps[j - 1];
            }

            else
            {
                // next character in text string
                i++;
            }
        }
    }

    return false;
}

bool areRotations(string &s1, string &s2)
{
    string txt = s1 + s1;
    string pat = s2;

    return kmpSearch(txt, pat);
}

int main()
{
    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1, s2) ? "true" : "false");
    return 0;
}