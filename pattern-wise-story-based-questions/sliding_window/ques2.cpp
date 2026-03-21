// A website tracks user visits per minute.

// Find the longest continuous period where the total visits do not exceed K.

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int traffic(vector<int> &arr, int k)
{
    int sum = 0;

    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        // expand the window -> include the no. of visits
        sum += arr[right];

        // shrink window -> until invlaid
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // keep track of the longest consecutive period
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    vector<int> visits = {1, 2, 1, 0, 1, 1, 0};
    int k = 4;

    cout << traffic(visits, k);
}