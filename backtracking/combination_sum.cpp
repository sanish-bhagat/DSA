#include <bits/stdc++.h>
using namespace std;

void makeCombination(vector<int> &arr, int remSum, vector<int> &curr, vector<vector<int>> &res, int index)
{
    // base case: if found a valid combination, store it
    if (remSum == 0)
    {
        res.push_back(curr);
        return;
    }

    // invalid case: cannot form the combination
    if (remSum < 0 || index >= arr.size())
        return;

    // add the curr element to the combination
    curr.push_back(arr[index]);

    // recurse with the same index and updated remSum
    makeCombination(arr, remSum - arr[index], curr, res, index);

    // backtrack: remove the curr element from the combination
    curr.pop_back();

    // recurse with the next index and same remSum
    makeCombination(arr, remSum, curr, res, index + 1);
}

//! TC is O(k * 2^k)
//! SC is O(k)

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    // store combination
    vector<int> curr;

    // store valid comobinations
    vector<vector<int>> res;

    // recursive soln
    makeCombination(arr, target, curr, res, 0);

    return res;
}

int main()
{
    vector<int> arr = {2, 6, 4, 8};
    int target = 8;

    vector<vector<int>> res = combinationSum(arr, target);

    for (vector<int> &v : res)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}