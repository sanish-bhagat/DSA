#include <bits/stdc++.h>
using namespace std;

// gives the total cost to make all towers height h
int findCost(vector<int> &heights, vector<int> cost, int h)
{
    int totalCost = 0;

    for (int i = 0; i < heights.size(); i++)
        totalCost += cost[i] * abs(heights[i] - h);

    return totalCost;
}

int minCost(vector<int> &heights, vector<int> &cost)
{
    int mini = INT_MAX, maxi = INT_MIN;

    // find min and max height
    for (int x : heights)
    {
        mini = min(mini, x);
        maxi = max(maxi, x);
    }

    // perform binary searach on the height
    int low = mini, high = maxi, ans;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int val1 = findCost(heights, cost, mid - 1);
        int val2 = findCost(heights, cost, mid);
        int val3 = findCost(heights, cost, mid + 1);

        // mid gives the lowest cost
        if (val2 <= val1 && val2 <= val3)
        {
            ans = val2;
            break;
        }

        // if decreasing side gives less cost
        else if (val1 >= val2 && val2 >= val3)
            low = mid + 1;

        // if increasing side gives less cost
        else if (val1 <= val2 && val2 <= val3)
            high = mid - 1;
    }

    return ans;
}

int main()
{
    vector<int> heights = {1, 2, 3};
    vector<int> cost = {10, 100, 1000};
    cout << minCost(heights, cost);
    return 0;
}