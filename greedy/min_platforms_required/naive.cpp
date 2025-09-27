#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // initially one platform is needed
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                // if trains have overlapping time, increment cnt
                // arrival time of the other train is less but departure time is more from the curr train then
                // timings overlap for these two trains                
                if (arr[i] >= arr[j] && dep[j] >= arr[i])
                    cnt++;
            }
        }

        // update with the max no of platforms required
        res = max(res, cnt);
    }

    return res;
}

int main()
{

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep);
    return 0;
}