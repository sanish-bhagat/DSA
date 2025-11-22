#include <bits/stdc++.h>
using namespace std;

//! TC is O(n logn)
//! SC is O(n)

int lis(vector<int> &arr)
{
    int n = arr.size();

    // list for a valid subsequence
    vector<int> ans;

    // include the first element in the subsequence
    ans.push_back(arr[0]);

    // itertate through the element of arr from left to right
    for (int i = 1; i < n; i++)
    {
        // founded a larger element in arr than the largest element of the subsequence -> include it in the subsequence
        if (arr[i] > ans.back())
            ans.push_back(arr[i]);

        // else, perform binary search to find the position at which we can insert the curr element and which would not affect the order in the subsequence
        else
        {
            // provides the required position for insertion
            int low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();

            // update in the list to maintain a sorted order in the subsequence
            ans[low] = arr[i];
        }
    }

    // return the length of the valid subsequence as the LIS
    return ans.size();
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lis(arr);
    return 0;
}