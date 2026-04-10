#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> find3Numbers(vector<int> &arr)
{
    int n = arr.size();

    if (n < 3)
        return {};

    // keep track of the values for a valid triplet
    // prevFirst -> tells the first no. according to index
    int first = INT_MAX, second = INT_MAX, prevFirst = INT_MAX;

    // traverse the arr[]
    for (int x : arr)
    {
        // update first and second smallest no.
        if (x <= first)
            first = x;

        else if (x <= second)
        {
            second = x;

            // update prevFirst based on index
            prevFirst = first;
        }

        // valid triplet found -> return
        else
            return {prevFirst, second, x};
    }

    // no valid triplet
    return {};
}

int main()
{
    vector<int> arr = {12, 11, 10, 5, 6, 2, 30};

    vector<int> res = find3Numbers(arr);

    for (int x : res)
        cout << x << " ";
}