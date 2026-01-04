#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int maxChainLength(vector<pair<int, int>> &pairs)
{
    int n = pairs.size();

    // sort the given pairs based on the second elements
    sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    // include the first pair in the chain
    int count = 1;
    int lastEnd = pairs[0].second;

    // traverse the sorted pairs
    for (int i = 1; i < n; i++)
    {
        // include the curr pair if it can follow the last chosen pair
        if (lastEnd < pairs[i].first)
        {
            count++;
            lastEnd = pairs[i].second;
        }
    }

    // return the max length of chain of pairs
    return count;
}

int main()
{
    vector<pair<int, int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLength(pairs);
    return 0;
}