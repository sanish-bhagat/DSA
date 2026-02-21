#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int hIndex(vector<int> &citations)
{
    int n = citations.size();

    // freq[]
    vector<int> freq(n + 1, 0);

    // count the freq of citations
    for (int c : citations)
    {
        if (c >= n)
            freq[n] += 1;

        else
            freq[c]++;
    }

    int idx = n;

    // variable to keep track of the count of papers
    // having at least idx citations
    int s = freq[n];

    while (s < idx)
    {
        idx--;
        s += freq[idx];
    }

    // return the largest index for which the count of
    // papers with at least idx citations becomes >= idx
    return idx;
}

int main()
{
    vector<int> arr = {3, 0, 5, 3, 0};
    cout << hIndex(arr);
}