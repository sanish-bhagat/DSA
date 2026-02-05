#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxOnes(vector<int> &arr, int k)
{
    int left = 0, sum = 0, maxLen = 0;

    // traverse every window from left to right
    for (int right = 0; right < arr.size(); right++)
    {
        // expand the window
        sum += arr[right];

        // shrink the window while we have more no. of 0's present in the window than k(we can flip)
        while ((right - left + 1) - sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // update the maxLen
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    int k = 2;
    vector<int> arr = {1, 0, 0, 1, 0, 1, 0, 1};

    cout << maxOnes(arr, k);
}