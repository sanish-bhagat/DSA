#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! SC is O(1)

vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
{
    int n = arr1.size(), m = arr2.size();

    // use two ptrs -> one at the start of the 1st arr and
    // another at the end of the 2nd arr
    int left = 0, right = m - 1;
    int diff = INT_MAX;

    vector<int> res(2);

    // traverse the two arr[] using two ptr technique
    while (left < n && right >= 0)
    {
        // curr sum of the two elements
        int sum = arr1[left] + arr2[right];

        // curr absolute diff of pair sum with given target
        int currDiff = abs(sum - x);

        // update the res if a closer pair is found
        if (currDiff < diff)
        {
            diff = currDiff;
            res[0] = arr1[left];
            res[1] = arr2[right];
        }

        // move the ptrs to bring the sum closer to target
        if (sum > x)
            right--;

        else
            left++;
    }

    return res;
}

int main()
{
    vector<int> arr1 = {1, 4, 5, 7};
    vector<int> arr2 = {10, 20, 30, 40};
    int x = 38;

    vector<int> closest = findClosestPair(arr1, arr2, x);

    cout << "[" << closest[0] << ", " << closest[1] << "]";
    return 0;
}