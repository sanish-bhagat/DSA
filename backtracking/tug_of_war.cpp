#include <bits/stdc++.h>
using namespace std;

void TwoUtil(vector<int> &arr, vector<bool> &curr, int sel, vector<bool> &resSel, int &minDiff, int totalSum, int currSum, int pos)
{
    int n = arr.size();

    // out of bound
    if (pos == n)
        return;

    // Check if that the number of elements left are not
    // less than the number of elements required to
    // form the solution
    if ((n / 2 - sel) > (n - pos))
        return;

    // Consider the case when current element is not included
    TwoUtil(arr, curr, sel, resSel, minDiff, totalSum, currSum, pos + 1);

    // Add the current element to the solution
    sel++;
    currSum += arr[pos];
    curr[pos] = true;

    // if any solution is found
    if (sel == n / 2)
    {

        // check if the curr solution, is the best so far
        int diff = abs(totalSum - 2 * currSum);

        if (diff < minDiff)
        {
            minDiff = diff;
            resSel = curr;
        }
    }
    else
    {
        // Consider the case where current element is included
        TwoUtil(arr, curr, sel, resSel, minDiff, totalSum, currSum, pos + 1);
    }

    // Remove current element before returning to the caller
    curr[pos] = false;
}

//! TC is O(2 ^ n)
//! SC is O(n)

pair<vector<int>, vector<int>> tugOfWar(vector<int> &arr)
{
    int n = arr.size();

    // Boolean array that contains inclusion/exclusion of an element
    vector<bool> curr(n, false);

    // Final solution mask
    vector<bool> resSel(n, false);

    int minDiff = INT_MAX;

    // total summ of arr[]
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // recursive soln
    TwoUtil(arr, curr, 0, resSel, minDiff, totalSum, 0, 0);

    // prepare two subsets
    vector<int> res1, res2;
    for (int i = 0; i < n; i++)
    {
        if (resSel[i])
            res1.push_back(arr[i]);

        else
            res2.push_back(arr[i]);
    }

    return {res1, res2};
}

int main()
{
    vector<int> arr = {3, 5, -3, 89, 54, 4, 100, 1, 23, 20};

    // Get the two subsets
    pair<vector<int>, vector<int>> res = tugOfWar(arr);

    // Print the subsets
    cout << "The first subset is: ";
    for (int x : res.first)
        cout << x << " ";

    cout << "\nThe second subset is: ";
    for (int x : res.second)
        cout << x << " ";

    return 0;
}