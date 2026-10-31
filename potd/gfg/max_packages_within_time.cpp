#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxPackages(vector<int> &arr, int totalTimes)
{
    int n = arr.size();

    // if time allows visiting all -> return total sum
    if (totalTimes >= n)
    {
        int total = 0;
        for (int x : arr)
            total += x;

        return total;
    }

    // first window packages
    int windowSum = 0;
    for (int i = 0; i < totalTimes; i++)
        windowSum += arr[i];

    int maxi = windowSum;

    // use sliding window technique to find the max no. of packages
    for (int i = totalTimes; i < n; i++)
    {
        // include the new packet and exlclude the out of window
        windowSum += arr[i];
        windowSum -= arr[i - totalTimes];

        // update the maxi
        maxi = max(maxi, windowSum);
    }

    return maxi;
}

int main()
{
    vector<int> arr = {2, 1, 3, 5, 0, 1, 4};

    int totalTime = 3;

    cout << maxPackages(arr, totalTime);
}