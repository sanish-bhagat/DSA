#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

bool canSplit(vector<int> &arr)
{
    // total sum of the arr[] elements
    int total = 0;
    for (int x : arr)
        total += x;

    // keep track of the left sum, i.e prefix sum
    int leftSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // include the curr element in the prefix sum
        leftSum += arr[i];

        // right sum, i.e suffix sum
        int rightSum = total - leftSum;

        // two subarrays have equal sum -> return true
        if (leftSum == rightSum)
            return true;
    }

    // no two subarrays have equal sum -> return false
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5};
    cout << canSplit(arr);
}