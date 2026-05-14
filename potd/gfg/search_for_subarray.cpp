#include <bits/stdc++.h>
using namespace std;

void constructLps(vector<int> &pat, vector<int> &lps)
{
    // len stores the length of longest prefix
    // which is also a suffix
    // for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;

    while (i < pat.size())
    {
        // if numbers match, increment the size of lps
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            // Update len to the previous lps value
            // to avoid reduntant comparisons
            if (len != 0)
                len = lps[len - 1];

            // If no matching prefix found,
            // set lps[i] to 0
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//! TC is O(n + m)
//! SC is O(m)

vector<int> search(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();

    vector<int> lps(m);
    vector<int> res;

    // build the lps[]
    constructLps(b, lps);

    // ptrs to traverse a[] and b[]
    int i = 0, j = 0;

    while (i < n)
    {
        // characters match -> move ptrs forward
        if (a[i] == b[j])
        {
            i++, j++;

            // all elements of b[] are present in a[],
            // store the starting index in res[]
            if (j == m)
            {
                res.push_back(i - j);

                j = lps[j - 1];
            }
        }

        // if there is a mismatch
        else
        {
            // use lps value of previous index to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1];

            else
                i++;
        }
    }

    return res;
}

int main()
{
    vector<int> a = {2, 4, 1, 0, 4, 1, 1}, b = {4, 1};

    vector<int> res = search(a, b);
    for (int x : res)
        cout << x << " ";
}