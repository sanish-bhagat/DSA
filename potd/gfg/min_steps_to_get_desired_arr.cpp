#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logm)
//! SC is O(1)

int countMinOperations(vector<int> &arr)
{
    // Tracks total increment operations (set bits)
    int incs = 0;

    // Tracks the maximum bit length found
    int maxLen = 0;

    for (int val : arr)
    {
        int len = 0;

        while (val > 0)
        {
            // An odd number (lowest bit set) implies an increment operation
            if (val & 1)
            {
                incs++;
            }
            len++;
            // Shift right to inspect the next bit
            val >>= 1;
        }

        maxLen = max(maxLen, len);
    }

    // Total doubling operations equals (max bit length - 1)
    int dbls = max(0, maxLen - 1);

    return incs + dbls;
}

int main()
{
    vector<int> arr = {2, 3};

    cout << countMinOperations(arr) << endl;

    return 0;
}