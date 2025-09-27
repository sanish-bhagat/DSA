#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * 2 ^ n)
//! SC is O(1)

int minElements(vector<int> &arr)
{
    int n = arr.size();

    // find the total sum of the arr[]
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    int bestSize = n + 1;

    // generate all subsets
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int subsetSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {

            // check whether the i-th element is a part of this subset or not
            if (mask & (1 << i))
            {
                subsetSum += arr[i];
                count++;
            }
        }

        // if curr subset sum is greater than the remaining sum
        if (subsetSum > totalSum - subsetSum)
            // find the size of the subset with the greater sum
            bestSize = min(bestSize, count);
    }

    return bestSize;
}

int main()
{
    vector<int> arr = {3, 1, 7, 1};
    cout << minElements(arr) << endl;
    return 0;
}