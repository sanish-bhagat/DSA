#include <bits/stdc++.h>
using namespace std;

int maxGap(vector<int> &bars)
{
    // sort the bars
    sort(bars.begin(), bars.end());

    int longest = 1, curr = 1;

    // traverse the sorted bars[] and find the longest consecutive sequence
    for (int i = 0; i < bars.size(); i++)
    {
        // values are continuous
        if (bars[i] == bars[i - 1] + 1)
            curr++;

        // else start a new sequence
        else
            curr = 1;

        // update the longest sequence
        longest = max(longest, curr);
    }

    // +1 because, gaps = bars removed + 1(base unit)
    return longest + 1;
}

//! TC is O(hlogh + vlogv)
//! SC is O(1)

int maxArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
{
    // find gap from the longest consecutive horizontal bars that can be removed
    int maxH = maxGap(hBars);

    // find gap from the longest consecutive vertical bars that can be removed
    int maxV = maxGap(vBars);

    // select the min gap to form a square
    int side = min(maxH, maxV);

    // return the area
    return side * side;
}

int main()
{
    int n = 2, m = 3;
    vector<int> hBars = {2, 3}, vBars = {2, 4};

    cout << maxArea(n, m, hBars, vBars);
}