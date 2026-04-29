#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int minSwaps(vector<int> &arr)
{
    int n = arr.size();

    // count the no. of ones in the given arr[]
    int numberOfOnes = 0;
    for (int x : arr)
    {
        if (x == 1)
            numberOfOnes++;
    }

    // no 1's present -> return -1
    if (numberOfOnes == 0)
        return -1;

    int x = numberOfOnes;

    int countOnes = 0, maxOnes;

    // no. of 1's in the first subarray of length x
    for (int i = 0; i < x; i++)
    {
        if (arr[i] == 1)
            countOnes++;
    }

    maxOnes = countOnes;

    // use sliding window to find max no. of ones in subarray of length x
    for (int i = 1; i <= n - x; i++)
    {
        // exlcude the out of window element
        if (arr[i - 1] == 1)
            countOnes--;

        // include the element
        if (arr[i + x - 1] == 1)
            countOnes++;

        if (maxOnes < countOnes)
            maxOnes = countOnes;
    }

    // no. of 0's in the subarray of length x with max no. of ones
    // will be the min swaps required to group all 1's together
    int numberOfZeros = x - maxOnes;

    return numberOfZeros;
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1, 1};
    cout << minSwaps(arr);
}