#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int minPlatform(vector<int> &arr, vector<int> &dep)
{
    int n = arr.size();
    int res = 0;

    // sort the arrival and departure time []
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // ptr for dep[]
    int j = 0;

    int cnt = 0;

    // traverse the arrival time[]
    for (int i = 0; i < n; i++)
    {
        // if any train has departed, before the arrival time of a new train then
        // decrement the cnt as it has freed up a platform
        while (j < n && dep[j] < arr[i])
        {
            cnt--;
            j++;
        }

        // allocate a new platform
        cnt++;

        // update the res
        res = max(cnt, res);
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