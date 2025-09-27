#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n logn)
//! SC is O(n)

int minCost(vector<int> &arr)
{
    int totalCost = 0;

    // process until more than 1 element is present in the arr[]
    while (arr.size() > 1)
    {
        // sort the arr[] in every step
        sort(arr.begin(), arr.end());

        // get the first two smallest elements
        int first = arr[0];
        int second = arr[1];

        // remove them from the arr[]
        arr.erase(arr.begin());
        arr.erase(arr.begin());

        // calculate the curr cost and the totalCost
        int cost = first + second;
        totalCost += cost;

        // insert the new rope cost into the arr[] for further calculation
        arr.push_back(cost);
    }

    return totalCost;
}

int main()
{

    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr);
    return 0;
}