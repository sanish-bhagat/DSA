#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxArea(vector<int> &height)
{
    // two ptrs technique
    int i = 0, j = height.size() - 1;

    int res = INT_MIN;

    while (i < j)
    {
        // curr area between the bars, area is always dependent on smaller bar
        int curr = min(height[i], height[j]) * (j - i - 1);

        // update global max area
        res = max(res, curr);

        // move the ptr with the smallest height
        if (height[i] <= height[j])
            i++;

        else
            j--;
    }

    return res;
}

int main()
{
    vector<int> height = {2, 5, 4, 3, 7};
    cout << maxArea(height);
}