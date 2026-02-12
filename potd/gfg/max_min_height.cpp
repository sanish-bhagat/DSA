#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to make every flower at least minHeight with given days
bool isPossible(vector<int> &arr, int k, int w, int maxHeight)
{
    int n = arr.size();
    vector<int> water(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            water[i] = water[i - 1];

        // curr height of the flower after watering it
        int currHeight = arr[i] + water[i];

        // remove watering effect for out of window flower
        if (i >= w)
            currHeight -= water[i - w];

        // curr height is less than required
        if (currHeight < maxHeight)
        {
            int add = maxHeight - currHeight;
            water[i] += add;
            k -= add;

            // days become -ve -> not possible
            if (k < 0)
                return false;
        }
    }

    return true;
}

int maxMinHeight(vector<int> &arr, int k, int w)
{
    int n = arr.size();

    // find the min height among the flowers
    int low = arr[0];
    for (int i = 1; i < arr.size(); i++)
        low = min(low, arr[i]);

    int high = low + k, ans = low;

    // binary search on the answer
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // possible -> move low as we have to find the max of min
        if (isPossible(arr, k, w, mid))
        {
            ans = max(ans, mid);
            low = mid + 1;
        }

        // not possible -> move high
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{

    vector<int> arr = {2, 3, 4, 5, 1};
    int k = 2;
    int w = 2;

    cout << maxMinHeight(arr, k, w);

    return 0;
}