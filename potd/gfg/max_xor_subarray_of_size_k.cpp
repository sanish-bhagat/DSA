#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSubarrayXOR(vector<int> &arr, int k)
{
    int windowXor = 0;

    // XOR of first k elements
    for (int i = 0; i < k; i++)
        windowXor ^= arr[i];

    int maxXor = windowXor;

    // traverse the other windows
    for (int i = k; i < arr.size(); i++)
    {
        // exclude the 1st element from the previous window
        windowXor ^= arr[i - k];

        // include the curr element in the curr window
        windowXor ^= arr[i];

        // update the max XOR
        maxXor = max(maxXor, windowXor);
    }

    return maxXor;
}

int main()
{
    int k = 2;
    vector<int> arr = {1, 2, 4, 5, 6};
    cout << maxSubarrayXOR(arr, k);
}