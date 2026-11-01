#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxSum(vector<int> &arr)
{
    // keep track of states
    // sq -> one element have been squared previously
    // noSq -> no element have been squared previously
    int sq = arr[0] * arr[0];
    int noSq = arr[0];

    int maxi = max(sq, noSq);

    for (int i = 1; i < arr.size(); i++)
    {
        // square the curr element
        int currSq = arr[i] * arr[i];

        // either start new subarray or,
        // extend the previuos sq sum by adding curr element or,
        // extend the noSq sum by adding the square of curr element
        int newSq = max({currSq, sq + arr[i], noSq + currSq});

        // either start new or extend the noSq sum
        noSq = max(arr[i], noSq + arr[i]);

        // update the states
        sq = newSq;
        maxi = max({maxi, sq, noSq});
    }

    return maxi;
}

int main()
{
    vector<int> arr = {-4, -4, -2, 5, 2, -1};
    cout << maxSum(arr);
}