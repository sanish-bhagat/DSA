#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxXorSubset(vector<int> &arr)
{
    // basis[i] will store a number whose
    // most significant set bit is at the i-th position
    vector<int> basis(32, 0);

    // build the basis[]
    for (int num : arr)
    {
        for (int i = 31; i >= 0; i--)
        {
            // i-th bit is set
            if ((num << i) & 1)
            {
                if (basis[i] == 0)
                {
                    basis[i] = num;
                    break;
                }

                // cancel out the bit
                num ^= basis[i];
            }
        }
    }

    // greedily find the max xor
    int maxXor = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((maxXor ^ basis[i]) > maxXor)
            maxXor ^= basis[i];
    }

    return maxXor;
}

int main()
{
    vector<int> arr = {7, 6, 5};
    cout << maxXorSubset(arr);
}