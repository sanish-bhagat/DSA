#include <bits/stdc++.h>
using namespace std;

void permutations(int idx, vector<vector<int>> &res, vector<int> &arr)
{
    // base case: traverse the arr[] -> store the curr permutation
    if (idx == arr.size())
    {
        res.push_back(arr);
        return;
    }

    // permutations made by swapping each element starting from index 'idx'
    for (int i = idx; i < arr.size(); i++)
    {
        // swap
        swap(arr[i], arr[idx]);

        // recurisve call to create permutations for the next element
        permutations(idx + 1, res, arr);

        // bactrack -> restore for the next possible permutation
        swap(arr[i], arr[idx]);
    }
}

//! TC is O(n! * n)
//! SC is O(n)

vector<vector<int>> permuteDist(vector<int> &arr)
{
    vector<vector<int>> res;

    // generate all permutations using backtracking
    permutations(0, res, arr);

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res = permuteDist(arr);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}