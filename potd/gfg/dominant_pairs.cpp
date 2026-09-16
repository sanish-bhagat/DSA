#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int dominantPairs(vector<int> &arr)
{
    int n = arr.size();

    // sort the first half in ascending order
    sort(arr.begin(), arr.begin() + n / 2);

    // sort the second half in ascending order
    sort(arr.begin() + n / 2, arr.end());

    int count = 0;

    // keep a right ptr at the start of the 2nd half
    int right = n / 2;

    for (int i = 0; i < n / 2; i++)
    {

        // keep on moving the ptr while dominance condition holds
        while (right < n && arr[i] >= 5 * arr[right])
            right++;

        // include all the dominant pairs count
        count += (right - n / 2);
    }

    return count;
}

int main()
{

    vector<int> arr = {10, 2, 2, 1};

    cout << dominantPairs(arr) << endl;

    return 0;
}