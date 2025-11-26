#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(k)

int numOfSubsets(vector<int> &arr, int k)
{
    int n = arr.size();

    // 1d[] to keep track of the prev and curr rows
    vector<int> prev(k + 1, 1), curr(k + 1, 1);

    // itertate through the elements in the arr
    for (int i = 1; i <= n; i++)
    {
        // copy previous state to the curr state(exclude curr element case)
        curr = prev;

        for (int j = 1; j <= k; j++)
        {
            // include the curr element, if and only if arr[i - 1] is less than equal to j
            if (j >= arr[i - 1])
                curr[j] += prev[j / arr[i - 1]];
        }

        // update the prev state with the curr state
        prev = curr;
    }

    // return the total count of the subsets, excluding the empty set
    return curr[k] - 1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << numOfSubsets(arr, k);
    return 0;
}