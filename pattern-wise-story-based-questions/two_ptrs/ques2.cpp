// A water management company installs vertical tanks along a straight road.
// Each tank has a height representing its water capacity.

// They want to select two tanks such that the water stored between them is maximized.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

// max water capacity
int maxWater(vector<int> &heights)
{
    int i = 0, j = heights.size() - 1;

    int ans = 0;

    while (i < j)
    {
        // curr water holding capacity
        int curr = min(heights[i], heights[j]) * (j - i);

        // update global max Capacity
        ans = max(ans, curr);

        // move ptrs
        if (heights[i] < heights[j])
            i++;

        else
            j--;
    }

    return ans;
}

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxWater(heights);
}