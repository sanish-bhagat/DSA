#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxWater(vector<int> &arr)
{
    // two ptrs
    int left = 0, right = arr.size() - 1;

    // keep track of the largest boundary of each side
    int lMax = 0, rMax = 0;

    int res = 0;

    // two ptr approach
    while (left <= right)
    {
        // left side boundary is smaller than right side ->
        // pick one with smaller boundary height,
        // because water is limited by the shorter boundary
        if (lMax <= rMax)
        {
            // founded a better(larger) boundary
            if (arr[left] >= lMax)
                lMax = arr[left];

            // include the curr water capacity
            else
                res += lMax - arr[left];

            // move the ptr forward
            left++;
        }

        // right has smaller boundary than left side
        else
        {
            // founded a better boundary
            if (arr[right] >= rMax)
                rMax = arr[right];

            // include curr water capacity
            else
                res += rMax - arr[right];

            // move the right ptr
            right--;
        }
    }

    // return the max Water that can be stored
    return res;
}

int main()
{
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout << maxWater(arr);
}