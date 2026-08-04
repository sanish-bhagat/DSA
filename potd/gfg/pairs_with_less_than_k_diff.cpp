#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int countPairs(int k, vector<int> &arr)
{
    // sort in increasing order
    sort(arr.begin(), arr.end());

    int cnt = 0, left = 0;

    // sliding window
    for (int right = 0; right < arr.size(); right++)
    {
        // shrink the window
        while (arr[right] - arr[left] >= k)
            left++;

        // take all the pairs that can be valid
        cnt += (right - left);
    }

    return cnt;
}

int main()
{
    int k = 5;
    vector<int> arr = {2, 4, 3};

    cout << countPairs(k, arr);
}